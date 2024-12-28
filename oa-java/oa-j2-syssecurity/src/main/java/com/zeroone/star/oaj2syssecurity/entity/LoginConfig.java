package com.zeroone.star.oaj2syssecurity.entity;

import io.github.classgraph.json.Id;
import lombok.Data;
import org.springframework.data.mongodb.core.mapping.Document;

/**
 * className: LoginConfig
 * author: maomaomao
 * date: 2024/10/28 18:58
 * Version: 1.0
 * description:
 */

@Data
@Document
public class LoginConfig {

    @Id
    int id;

    /**
     * 是否启用图片验证码
     */
    private Boolean enablePicLogin;

    /**
     * 是否启用短信验证码登录
     */
    private Boolean enableSmsLogin;

}
