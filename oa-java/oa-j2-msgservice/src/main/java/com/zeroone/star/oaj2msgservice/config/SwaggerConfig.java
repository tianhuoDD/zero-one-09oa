package com.zeroone.star.oaj2msgservice.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.beans.factory.annotation.Configurable;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket MessageNotifyServiceApi(){
        return SwaggerCore.defaultDocketBuilder("消息通知服务","com.zeroone.star.oaj2msgservice.controller","msgservice");
    }
}
