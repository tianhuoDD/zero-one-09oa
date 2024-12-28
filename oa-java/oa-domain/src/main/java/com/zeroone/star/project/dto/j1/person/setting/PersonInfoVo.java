package com.zeroone.star.project.dto.j1.person.setting;


import lombok.Data;

@Data
public class PersonInfoVo {

    /**
     * 唯一表示符
     */
    private String id;
    /**
     * 邮箱
     */
    private String mail;
    /**
     * 微信
     */
    private String wexin;
    /**
     * QQ
     */
    private Long qq;
    /**
     * 论坛名
     */
    private String bbsName;
    /**
     * 个性签名
     */
    private String single;
    /**
     * 头像地址
     */
    private String head;
    /**
     * 手机验证码
     */
    private String phoneCode;


}
