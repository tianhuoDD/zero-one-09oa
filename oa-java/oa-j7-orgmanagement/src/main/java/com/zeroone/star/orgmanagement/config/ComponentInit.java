package com.zeroone.star.orgmanagement.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 注册自定义组件
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.easyexcel",
})
public class ComponentInit {

}
