package com.zeroone.star.orgmanagement.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

/** 导出的实体类
 * @author: zlw
 * @date: 2024-10-25
 */
@Data
public class EasyExcelOrgPerson {

    @ExcelProperty("人员名字")
    private String name;

    @ExcelProperty("唯一编码")
    private String uniqueCode;

    @ExcelProperty("手机号码")
    private String mobilePhone;

    @ExcelProperty("人员编号")
    private String personCode;

    @ExcelProperty("办公电话")
    private String phone;

    @ExcelProperty("性别")
    private String sex;

    @ExcelProperty("邮件")
    private String email;
}
