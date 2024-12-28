package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import lombok.Builder;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;



@Data
@TableName("qry_item")
public class QryItem implements Serializable {

    private static final long serialVersionUID = 1L;


    /**
     * 唯一标识
     * 示例: "76c920fd-eade-4afd-b1b4-c4b2c9515b6f"
     */
    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    /**
     * 创建时间
     * 示例: "2024-10-27T15:56:41"
     */
    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     * 示例: "20241027155641abc123"
     */
    @TableField("xsequence")
    private String xsequence;


    /**
     * 更新时间
     * 示例: "2024-10-27T16:00:00"
     */
    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    /**
     * 分发因子
     * 示例: 10
     */
    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    /**
     * 布尔值
     * 示例: true
     */
    @TableField("xbooleanValue")
    private Boolean xbooleanValue;

    /**
     * 关联包
     * 示例: "myBundle"
     */
    @TableField("xbundle")
    private String xbundle;

    /**
     * 日期时间值
     * 示例: "2024-10-27T15:56:41"
     */
    @TableField("xdateTimeValue")
    private LocalDateTime xdateTimeValue;

    /**
     * 日期值
     * 示例: "2024-10-27"
     */
    @TableField("xdateValue")
    private Date xdateValue;

    /**
     * 项目类别
     * 示例: "类型A"
     */
    @TableField("xitemCategory")
    private String xitemCategory;

    /**
     * 项目原始类型
     * 示例: "S"
     */
    @TableField("xitemPrimitiveType")
    private String xitemPrimitiveType;

    /**
     * 项目字符串值类型
     * 示例: "10"
     */
    @TableField("xitemStringValueType")
    private String xitemStringValueType;

    /**
     * 项目类型
     * 示例: "A"
     */
    @TableField("xitemType")
    private String xitemType;

    /**
     * 数值
     * 示例: 123.45
     */
    @TableField("xnumberValue")
    private Double xnumberValue;

    /**
     * 路径0
     * 示例: "path0"
     */
    @TableField("xpath0")
    private String xpath0;

    /**
     * 路径0位置
     * 示例: 1
     */
    @TableField("xpath0Location")
    private Integer xpath0Location;

    /**
     * 路径1
     * 示例: "path1"
     */
    @TableField("xpath1")
    private String xpath1;

    /**
     * 路径1位置
     * 示例: 2
     */
    @TableField("xpath1Location")
    private Integer xpath1Location;

    /**
     * 路径2
     * 示例: "path2"
     */
    @TableField("xpath2")
    private String xpath2;

    /**
     * 路径2位置
     * 示例: 3
     */
    @TableField("xpath2Location")
    private Integer xpath2Location;

    /**
     * 路径3
     * 示例: "path3"
     */
    @TableField("xpath3")
    private String xpath3;

    /**
     * 路径3位置
     * 示例: 4
     */
    @TableField("xpath3Location")
    private Integer xpath3Location;

    /**
     * 路径4
     * 示例: "path4"
     */
    @TableField("xpath4")
    private String xpath4;

    /**
     * 路径4位置
     * 示例: 5
     */
    @TableField("xpath4Location")
    private Integer xpath4Location;

    /**
     * 路径5
     * 示例: "path5"
     */
    @TableField("xpath5")
    private String xpath5;

    /**
     * 路径5位置
     * 示例: 6
     */
    @TableField("xpath5Location")
    private Integer xpath5Location;

    /**
     * 路径6
     * 示例: "path6"
     */
    @TableField("xpath6")
    private String xpath6;

    /**
     * 路径6位置
     * 示例: 7
     */
    @TableField("xpath6Location")
    private Integer xpath6Location;

    /**
     * 路径7
     * 示例: "path7"
     */
    @TableField("xpath7")
    private String xpath7;

    /**
     * 路径7位置
     * 示例: 8
     */
    @TableField("xpath7Location")
    private Integer xpath7Location;

    /**
     * 长字符串值
     * 示例: "这是一个长字符串"
     */
    @TableField("xstringLongValue")
    private String xstringLongValue;

    /**
     * 短字符串值
     * 示例: "短字符串"
     */
    @TableField("xstringShortValue")
    private String xstringShortValue;

    /**
     * 时间值
     * 示例: "15:30:00"
     */
    @TableField("xtimeValue")
    private LocalTime xtimeValue;
}

