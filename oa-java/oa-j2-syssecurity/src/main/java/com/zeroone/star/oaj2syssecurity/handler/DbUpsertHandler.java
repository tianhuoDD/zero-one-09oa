package com.zeroone.star.oaj2syssecurity.handler;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import lombok.extern.slf4j.Slf4j;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.Optional;

/**
 * 数据插入/更新自动填充字段
 * @author JIAN
 */
@Slf4j
@Component
public class DbUpsertHandler implements MetaObjectHandler {
    @Resource
    private UserHolder userHolder;

    private String getUserId() {
        try {
            return Optional
                    .ofNullable(userHolder.getCurrentUser())
                    .map(UserDTO::getId)
                    .orElse("");
        } catch (Exception e) {
            // TODO 测试使用
            return "";
            // 包装运行时异常抛出同时防止过度包装
            // log.warn("获取用户id出错", e);
            // throw e instanceof RuntimeException ? (RuntimeException) e : new RuntimeException(e);
        }
    }

    @Override
    public void insertFill(MetaObject metaObject) {
        log.info("新增数据填充创建时间和创建人");
        this.strictInsertFill(metaObject, "createBy", String.class, this.getUserId());
        this.strictInsertFill(metaObject, "createTime", LocalDateTime.class, LocalDateTime.now());
        this.strictInsertFill(metaObject, "updateBy", String.class, this.getUserId());
        this.strictInsertFill(metaObject, "updateTime", LocalDateTime.class, LocalDateTime.now());
    }

    @Override
    public void updateFill(MetaObject metaObject) {
        log.info("更新数据填充更新时间和更新人");
        this.strictInsertFill(metaObject, "updateBy", String.class, this.getUserId());
        this.strictInsertFill(metaObject, "updateTime", LocalDateTime.class, LocalDateTime.now());
    }
}