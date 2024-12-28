package com.zeroone.star.procmanager.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {

    @Bean
    Docket SampleApi(){
        return SwaggerCore.defaultDocketBuilder("流程管理示例模块","com.zeroone.star.procmanager.controller",
                "procmanager");
    }
}
