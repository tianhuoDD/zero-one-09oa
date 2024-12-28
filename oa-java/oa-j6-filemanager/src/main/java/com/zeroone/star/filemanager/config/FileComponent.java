package com.zeroone.star.filemanager.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * @program: oa-java
 * @description:
 * @author: Mr.Wang
 * @create: 2024-10-25 17:07
 **/
@Configuration
@ComponentScan("com.zeroone.star.project.components.fastdfs")
@ComponentScan("com.zeroone.star.project.components.user")
@ComponentScan("com.zeroone.star.project.components.jwt")
public class FileComponent {
}
