package com.zeroone.star.calmanager.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket followCalendarApis() {
        return SwaggerCore.defaultDocketBuilder("日程安排",
                "com.zeroone.star.calmanager.controller",
                "calendar");
    }
}
