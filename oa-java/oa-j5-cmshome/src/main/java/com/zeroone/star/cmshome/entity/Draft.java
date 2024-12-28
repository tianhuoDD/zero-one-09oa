package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;

@Data
@TableName("pp_e_draft")
public class Draft {

    // 主键，唯一标识
    // value: xid
    // example: "12345-abcde-67890"
    private String xid;

    // 创建时间
    // value: xcreateTime
    // example: "2024-10-23 14:22:35"
    private Date xcreateTime;

    // 序列
    // value: xsequence
    // example: "SEQ20241023"
    private String xsequence;

    // 更新时间
    // value: xupdateTime
    // example: "2024-10-23 16:45:00"
    private Date xupdateTime;

    // 分发因子
    // value: xdistributeFactor
    // example: 1
    private Integer xdistributeFactor;

    // 应用标识
    // value: xapplication
    // example: "APP001"
    private String xapplication;

    // 应用别名
    // value: xapplicationAlias
    // example: "应用A"
    private String xapplicationAlias;

    // 应用名称
    // value: xapplicationName
    // example: "Application A"
    private String xapplicationName;

    // 身份标识
    // value: xidentity
    // example: "IDENTITY_001"
    private String xidentity;

    // 相关人员
    // value: xperson
    // example: "张三"
    private String xperson;

    // 流程标识
    // value: xprocess
    // example: "PROC001"
    private String xprocess;

    // 流程别名
    // value: xprocessAlias
    // example: "流程A"
    private String xprocessAlias;

    // 流程名称
    // value: xprocessName
    // example: "Process A"
    private String xprocessName;

    // 其他属性
    // value: xproperties
    // example: "{'key1': 'value1', 'key2': 'value2'}"
    private String xproperties;

    // 标题
    // value: xtitle
    // example: "任务标题"
    private String xtitle;

    // 单位
    // value: xunit
    // example: "单位A"
    private String xunit;

    // Getters and Setters omitted for brevity
}

