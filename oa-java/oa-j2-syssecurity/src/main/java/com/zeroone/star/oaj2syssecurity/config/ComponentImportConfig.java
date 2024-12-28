package com.zeroone.star.oaj2syssecurity.config;

import com.zeroone.star.project.components.jwt.JwtComponent;
import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;

/**
 * 导入common包下的封装组件
 * @author JIAN
 */
@Configuration
@Import({UserHolder.class, JwtComponent.class})
public class ComponentImportConfig {
}