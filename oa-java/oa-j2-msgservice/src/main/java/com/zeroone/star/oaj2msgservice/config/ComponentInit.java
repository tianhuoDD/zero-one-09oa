package com.zeroone.star.oaj2msgservice.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 组件初始化
 * @author qingjiu
 */
@Configuration
@ComponentScan({"com.zeroone.star.project.components.mail"
               ,"com.zeroone.star.project.components.sms"})
public class ComponentInit {
}
