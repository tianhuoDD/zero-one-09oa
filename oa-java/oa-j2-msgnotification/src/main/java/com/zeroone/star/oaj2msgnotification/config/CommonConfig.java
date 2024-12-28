package com.zeroone.star.oaj2msgnotification.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 公共组件配置类
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.jwt"
})
public class CommonConfig {
}
