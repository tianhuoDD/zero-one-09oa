package com.zeroone.star.settings.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@ComponentScan("com.zeroone.star.project.components.sms.aliyun")
@ComponentScan("com.zeroone.star.project.components.mail")
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket settingsApi() {
        return SwaggerCore.defaultDocketBuilder("个人设置","com.zeroone.star.settings.controller","settings");
    }

}
