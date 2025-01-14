package com.zeroone.star.cmshome.config;


import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket Api(){
        return SwaggerCore.defaultDocketBuilder("内容管理首页","com.zeroone.star.cmshome.controller","cms");
    }
}
