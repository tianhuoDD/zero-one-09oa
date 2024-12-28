package com.zeroone.star.columnsetting.config;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import lombok.extern.slf4j.Slf4j;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;

//公共字段自动填充
@Component
@Slf4j
public class MyMetaObjectHandler implements MetaObjectHandler {
    @Override
    public void insertFill(MetaObject metaObject) {
        metaObject.setValue("xcreateTime", LocalDateTime.now());
        metaObject.setValue("xupdateTime", LocalDateTime.now());

    }

    @Override
    public void updateFill(MetaObject metaObject) {
        metaObject.setValue("xupdateTime", LocalDateTime.now());
        metaObject.setValue("xlastUpdateTime", LocalDateTime.now());

    }
}
