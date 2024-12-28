package com.zeroone.star.oaj2syssecurity.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.collection.CollectionUtil;
import cn.hutool.core.util.ObjectUtil;
import cn.hutool.json.JSONUtil;
import com.zeroone.star.oaj2syssecurity.entity.UserPasswordConfig;
import com.zeroone.star.oaj2syssecurity.enums.UserPasswordConfigEnum;
import com.zeroone.star.oaj2syssecurity.enums.UserPasswordGenerateWayEnum;
import com.zeroone.star.oaj2syssecurity.enums.UserPasswordRuleEnum;
import com.zeroone.star.oaj2syssecurity.mapper.SystemSecUserPasswordConfigRepository;
import com.zeroone.star.oaj2syssecurity.service.ISystemSecUserPasswordConfigService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j2.system.security.password.UserPasswordConfigDTO;
import com.zeroone.star.project.vo.j2.system.security.password.UserPasswordConfigVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.lang.reflect.Method;
import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

/**
 * 用户密码配置业务层实现
 * @author JIAN
 */
@Slf4j
@Service
public class SystemSecUserPasswordConfigServiceImpl implements ISystemSecUserPasswordConfigService {
    private final Map<Integer, Method> DTO_GETTER_MAP = new HashMap<>();
    @Resource
    private UserHolder userHolder;
    @Resource
    private SystemSecUserPasswordConfigRepository repository;

    public SystemSecUserPasswordConfigServiceImpl() {
        for (UserPasswordConfigEnum configEnum : UserPasswordConfigEnum.values()) {
            // 缓存DTO中值的获取函数
            Method readMethod = BeanUtil
                    .getPropertyDescriptor(UserPasswordConfigDTO.class, configEnum.getField())
                    .getReadMethod();
            DTO_GETTER_MAP.put(configEnum.getId(), readMethod);
        }
    }

    @Override
    public UserPasswordConfigVO getAllConfigOrDefault() {
        // 获取并转化数据库中的数据
        Map<Integer, String> configMap = repository
                .findAll()
                .stream()
                .collect(Collectors.toMap(UserPasswordConfig::getId, UserPasswordConfig::getValue));

        UserPasswordConfigEnum defaultPasswordGenerateWay = UserPasswordConfigEnum.DEFAULT_PASSWORD_GENERATE_WAY;
        UserPasswordConfigEnum defaultPasswordAdditionInfo = UserPasswordConfigEnum.DEFAULT_PASSWORD_ADDITION_INFO;
        UserPasswordConfigEnum passwordExpireTime = UserPasswordConfigEnum.PASSWORD_EXPIRE_TIME;
        UserPasswordConfigEnum passwordLengthMin = UserPasswordConfigEnum.PASSWORD_LENGTH_MIN;
        UserPasswordConfigEnum passwordLengthMax = UserPasswordConfigEnum.PASSWORD_LENGTH_MAX;
        UserPasswordConfigEnum passwordRule = UserPasswordConfigEnum.PASSWORD_RULE;
        UserPasswordConfigEnum isEnableEncryptedSend = UserPasswordConfigEnum.IS_ENABLE_ENCRYPTED_SEND;
        UserPasswordConfigEnum isEnableForceChange = UserPasswordConfigEnum.IS_ENABLE_FORCE_CHANGE;

        // 组装数据
        return UserPasswordConfigVO.builder()
                .defaultPasswordGenerateWay(Integer.parseInt(configMap.getOrDefault(defaultPasswordGenerateWay.getId(), defaultPasswordGenerateWay.getDefaultValue())))
                .defaultPasswordAdditionInfo(configMap.getOrDefault(defaultPasswordAdditionInfo.getId(), defaultPasswordAdditionInfo.getDefaultValue()))
                .passwordExpireTime(Integer.parseInt(configMap.getOrDefault(passwordExpireTime.getId(), passwordExpireTime.getDefaultValue())))
                .passwordLengthMin(Integer.parseInt(configMap.getOrDefault(passwordLengthMin.getId(), passwordLengthMin.getDefaultValue())))
                .passwordLengthMax(Integer.parseInt(configMap.getOrDefault(passwordLengthMax.getId(), passwordLengthMax.getDefaultValue())))
                .passwordRule(JSONUtil.parseArray(configMap.getOrDefault(passwordRule.getId(), passwordRule.getDefaultValue())).toList(String.class))
                .isEnableEncryptedSend(Boolean.parseBoolean(configMap.getOrDefault(isEnableEncryptedSend.getId(), isEnableEncryptedSend.getDefaultValue())))
                .isEnableForceChange(Boolean.parseBoolean(configMap.getOrDefault(isEnableForceChange.getId(), isEnableForceChange.getDefaultValue())))
                .build();
    }

    /**
     * 校验参数
     */
    private void validateDTO(UserPasswordConfigDTO dto) {
        // 自动纠正最大最小参数反转的问题
        Integer passwordLengthMin = dto.getPasswordLengthMin();
        Integer passwordLengthMax = dto.getPasswordLengthMax();
        // 防止更新后数据库中的数据错误
        if (ObjectUtil.isEmpty(passwordLengthMin)) {
            passwordLengthMin = Integer.parseInt(repository
                    .findById(UserPasswordConfigEnum.PASSWORD_LENGTH_MIN.getId())
                    .map(UserPasswordConfig::getValue)
                    .orElse(UserPasswordConfigEnum.PASSWORD_LENGTH_MIN.getDefaultValue()));
        }
        if (ObjectUtil.isEmpty(passwordLengthMax)) {
            passwordLengthMax = Integer.parseInt(repository
                    .findById(UserPasswordConfigEnum.PASSWORD_LENGTH_MAX.getId())
                    .map(UserPasswordConfig::getValue)
                    .orElse(UserPasswordConfigEnum.PASSWORD_LENGTH_MAX.getDefaultValue()));
        }
        if (ObjectUtil.isNotEmpty(passwordLengthMin) && ObjectUtil.isNotEmpty(passwordLengthMax) && passwordLengthMin > passwordLengthMax) {
            dto.setPasswordLengthMax(passwordLengthMin);
            dto.setPasswordLengthMin(passwordLengthMax);
        }

        Integer defaultPasswordGenerateWay = dto.getDefaultPasswordGenerateWay();
        if (ObjectUtil.isEmpty(dto.getDefaultPasswordAdditionInfo())
                && (UserPasswordGenerateWayEnum.BY_CODE.getCode().equals(defaultPasswordGenerateWay)
                || UserPasswordGenerateWayEnum.BY_COMMAND.getCode().equals(defaultPasswordGenerateWay))) {
            throw new RuntimeException("口令/脚本缺失无法更新");
        }

        if (CollectionUtil.isNotEmpty(dto.getPasswordRule())) {
            // 去重
            dto.setPasswordRule(dto.getPasswordRule().stream().distinct().collect(Collectors.toList()));

            List<String> ruleList = Arrays
                    .stream(UserPasswordRuleEnum.values())
                    .map(UserPasswordRuleEnum::getDescription)
                    .collect(Collectors.toList());

            outer:
            for (String dtoRule : dto.getPasswordRule()) {
                for (String rule : ruleList) {
                    if (rule.equals(dtoRule)) {
                        continue outer;
                    }
                }
                throw new RuntimeException("密码规则错误无法更新");
            }
        }
    }

    /**
     * 获取当前用户id
     */
    private String getUserId() {
        try {
            return Optional
                    .ofNullable(userHolder.getCurrentUser())
                    .map(UserDTO::getId)
                    .orElse("");
        } catch (Exception e) {
            // 包装运行时异常抛出同时防止过度包装
            log.warn("获取用户id出错", e);
            throw e instanceof RuntimeException ? (RuntimeException) e : new RuntimeException(e);
        }
    }

    @Override
    public void saveOrUpdateConfig(UserPasswordConfigDTO userPasswordConfigDTO) {
        // 二次校验无法简答校验的规则
        this.validateDTO(userPasswordConfigDTO);
        String userId = this.getUserId();
        LocalDateTime now = LocalDateTime.now();

        try {
            for (UserPasswordConfigEnum configEnum : UserPasswordConfigEnum.values()) {
                // 获取缓存的DTO函数读取值
                Method readMethod = DTO_GETTER_MAP.get(configEnum.getId());

                Optional.ofNullable(readMethod.invoke(userPasswordConfigDTO))
                        .map(Object::toString)
                        .ifPresent(configVal -> {
                            UserPasswordConfig userPasswordConfig = UserPasswordConfig.builder()
                                    .id(configEnum.getId())
                                    .name(configEnum.getField())
                                    .value(configVal)
                                    .updateBy(userId)
                                    .updateTime(now)
                                    .build();
                            UserPasswordConfig config = repository.findById(configEnum.getId()).orElse(null);
                            if (config == null) {
                                userPasswordConfig.setCreateTime(now);
                                userPasswordConfig.setCreateBy(userId);
                            } else {
                                userPasswordConfig.setCreateBy(config.getCreateBy());
                                userPasswordConfig.setCreateTime(config.getCreateTime());
                            }
                            // save <=> upsert
                            repository.save(userPasswordConfig);
                        });
            }
        } catch (Exception e) {
            throw e instanceof RuntimeException ? (RuntimeException) e : new RuntimeException(e);
        }
    }
}