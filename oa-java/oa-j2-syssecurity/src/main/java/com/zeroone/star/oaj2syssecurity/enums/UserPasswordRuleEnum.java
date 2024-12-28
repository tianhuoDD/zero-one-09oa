package com.zeroone.star.oaj2syssecurity.enums;

import lombok.AllArgsConstructor;
import lombok.Getter;

/**
 * 用户密码规则枚举
 * @author JIAN
 */
@Getter
@AllArgsConstructor
public enum UserPasswordRuleEnum {
    HAVING_LOWER_CASE(1, "必须包含小写字母"),
    HAVING_NUMBER(2, "必须包含数字"),
    HAVING_UPPER_CASE(3, "必须包含大写字母"),
    HAVING_SPECIAL(4, "必须包含特殊字符(#?!@$%^&*-)");

    /**
     * 编号
     */
    private final Integer code;

    /**
     * 中文描述
     */
    private final String description;
}