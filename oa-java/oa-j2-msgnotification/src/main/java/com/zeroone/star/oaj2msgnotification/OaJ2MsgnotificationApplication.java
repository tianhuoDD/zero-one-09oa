package com.zeroone.star.oaj2msgnotification;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
//@MapperScan("com.zeroone.star.oaj2msgnotification.mapper")
@EnableDiscoveryClient
public class OaJ2MsgnotificationApplication {

    public static void main(String[] args) {
        SpringApplication.run(OaJ2MsgnotificationApplication.class, args);
    }

}
