package com.zeroone.star.oaj2syssecurity.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.jwt",
})
public class ComponentInit {
}