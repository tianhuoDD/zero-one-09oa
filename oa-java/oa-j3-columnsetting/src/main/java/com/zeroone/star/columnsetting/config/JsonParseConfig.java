package com.zeroone.star.columnsetting.config;

import com.zeroone.star.columnsetting.utils.JsonParse;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class JsonParseConfig {
    @Bean
    public JsonParse jsonParse(){
        return new JsonParse();
    }
}
