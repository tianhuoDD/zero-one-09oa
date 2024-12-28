package com.zeroone.star.oauth2;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.security.crypto.password.PasswordEncoder;

import javax.annotation.Resource;

import static java.lang.Thread.sleep;

@SpringBootTest
class Oauth2ApplicationTests {
    @Resource
    PasswordEncoder passwordEncoder;

    @Test
    void contextLoads() throws InterruptedException {
        System.out.println(passwordEncoder.encode("123456"));
        Thread.sleep(30000);
    }

}
