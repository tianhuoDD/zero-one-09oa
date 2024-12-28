package com.zeroone.star.oaj2msgservice;


import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.scheduling.annotation.EnableScheduling;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@SpringBootApplication
@EnableDiscoveryClient
@EnableSwagger2WebMvc
@MapperScan("com.zeroone.star.oaj2msgservice.mapper")
@EnableBinding(Sink.class)
@EnableScheduling
@EnableFeignClients
public class OaJ2MsgserviceApplication {

    public static void main(String[] args) {
        SpringApplication.run(OaJ2MsgserviceApplication.class, args);
    }

}
