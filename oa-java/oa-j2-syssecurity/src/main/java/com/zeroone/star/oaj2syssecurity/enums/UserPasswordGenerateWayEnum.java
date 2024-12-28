package com.zeroone.star.oaj2syssecurity.enums;

import lombok.AllArgsConstructor;
import lombok.Getter;

/**
 * 用户密码生成方式枚举类
 * @author JIAN
 */
@Getter
@AllArgsConstructor
public enum UserPasswordGenerateWayEnum {
    BY_PHONE(1, "手机号码后六位"),
    BY_ID(2, "唯一编码后六位"),
    BY_NO(3, "人员工号"),
    BY_NAME(4, "人员名称全拼"),
    BY_CODE(5, "固定口令"),
    BY_COMMAND(6, "通过脚本自定义生成密码");

    /**
     * 编号
     */
    private final Integer code;

    /**
     * 中文描述
     */
    private final String description;
}