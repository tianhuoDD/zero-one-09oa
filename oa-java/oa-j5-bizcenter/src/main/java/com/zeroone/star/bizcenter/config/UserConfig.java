package com.zeroone.star.bizcenter.config;

import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class UserConfig {
    @Bean
    public UserHolder userHolder() {
        return new UserHolder();
    }
}
