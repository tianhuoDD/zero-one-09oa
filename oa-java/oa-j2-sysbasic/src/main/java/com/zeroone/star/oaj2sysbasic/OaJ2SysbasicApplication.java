package com.zeroone.star.oaj2sysbasic;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.data.mongodb.repository.config.EnableMongoRepositories;

@SpringBootApplication
@EnableDiscoveryClient
//@EnableMongoRepositories("com.zeroone.star.oaj2sysbasic.mapper")
public class OaJ2SysbasicApplication {

    public static void main(String[] args) {
        SpringApplication.run(OaJ2SysbasicApplication.class, args);
    }

}
