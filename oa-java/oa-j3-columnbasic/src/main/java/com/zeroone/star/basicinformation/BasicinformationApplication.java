package com.zeroone.star.basicinformation;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableDiscoveryClient
@EnableFeignClients
public class BasicinformationApplication {

    /**
     * 栏目基础信息设置启动入口
     * @param args
     */
    public static void main(String[] args) {
        SpringApplication.run(BasicinformationApplication.class, args);
    }
}
