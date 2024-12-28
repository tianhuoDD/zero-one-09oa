package com.zeroone.star.orgmanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@SpringBootApplication
public class OrgManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(OrgManagementApplication.class, args);
    }
}