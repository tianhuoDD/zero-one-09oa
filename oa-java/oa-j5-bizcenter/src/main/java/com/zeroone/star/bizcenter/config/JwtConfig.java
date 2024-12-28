package com.zeroone.star.bizcenter.config;

import com.zeroone.star.project.components.jwt.JwtComponent;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class JwtConfig {
    @Bean
    public JwtComponent jwtComponent() {
        return new JwtComponent();
    }
}
