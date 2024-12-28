package com.zeroone.star.filemanager.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket FileApi(){
        return SwaggerCore.defaultDocketBuilder("企业网盘文件模块",
                "com.zeroone.star.filemanager.controller",
                "fileAttachment");
    }
}

