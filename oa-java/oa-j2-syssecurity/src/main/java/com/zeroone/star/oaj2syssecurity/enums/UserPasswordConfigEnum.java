package com.zeroone.star.oaj2syssecurity.enums;

import lombok.AllArgsConstructor;
import lombok.Getter;

import java.util.Arrays;

/**
 * 用户密码配置枚举类
 * @author JIAN
 */
@Getter
@AllArgsConstructor
public enum UserPasswordConfigEnum {
    DEFAULT_PASSWORD_GENERATE_WAY(1, "defaultPasswordGenerateWay", UserPasswordGenerateWayEnum.BY_ID.getCode().toString()),
    DEFAULT_PASSWORD_ADDITION_INFO(2, "defaultPasswordAdditionInfo", null),
    PASSWORD_EXPIRE_TIME(3, "passwordExpireTime", "0"),
    PASSWORD_LENGTH_MIN(4, "passwordLengthMin", "8"),
    PASSWORD_LENGTH_MAX(5, "passwordLengthMax", "30"),
    PASSWORD_RULE(6, "passwordRule", Arrays.toString(new String[]{
            UserPasswordRuleEnum.HAVING_LOWER_CASE.getDescription(),
            UserPasswordRuleEnum.HAVING_NUMBER.getDescription()})),
    IS_ENABLE_ENCRYPTED_SEND(7, "isEnableEncryptedSend", "false"),
    IS_ENABLE_FORCE_CHANGE(8, "isEnableForceChange", "false");

    /**
     * 配置在数据中的主键
     */
    private final Integer id;

    /**
     * 配置名称(便于数据库显示)
     */
    private final String field;

    /**
     * 配置的默认值
     */
    private final String defaultValue;
}