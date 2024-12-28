package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

/**
 * <p>
 *  数据配置字典do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-22
 */
@Getter
@Setter
@TableName("pp_e_applicationdictitem")
public class PpEApplicationdictitem implements Serializable {

    private static final long serialVersionUID = 1L;
//    唯一标识符
    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;
//    创建时间，记录该条记录被创建的时间戳
    private LocalDateTime xcreateTime;
//    序列号
    private String xsequence;
//    更新时间
    private LocalDateTime xupdateTime;
//    分发因子，用于控制数据分发、负载均衡
    private Integer xdistributeFactor;
//    应用程序
    private String xapplication;
//    布尔值，表示状态
    private Boolean xbooleanValue;
//    捆绑包
    private String xbundle;
//    日期时间值，存储具体的日期和时间信息
    private LocalDateTime xdateTimeValue;
//    日期值，仅存储日期信息，不包含时间
    private LocalDate xdateValue;
//    项目类别，表示该条记录所属的分类或类型
    private String xitemCategory;
//    项目原始类型
    private String xitemPrimitiveType;
//    项目字符串值类型，进一步细化字符串值的类型（如电子邮件、URL、密码等）
    private String xitemStringValueType;
//    项目类型
    private String xitemType;
//    数值，存储数字类型的值
    private Double xnumberValue;
//    路径
    private String xpath0;
//    路径位置
    private Integer xpath0Location;
//    路径
    private String xpath1;
    //    路径位置
    private Integer xpath1Location;
//    路径
    private String xpath2;
    //    路径位置
    private Integer xpath2Location;
//    路径
    private String xpath3;
    //    路径位置
    private Integer xpath3Location;
//    路径
    private String xpath4;
    //    路径位置
    private Integer xpath4Location;
//    路径
    private String xpath5;
    //    路径位置
    private Integer xpath5Location;
//    路径
    private String xpath6;
    //    路径位置
    private Integer xpath6Location;
//    路径
    private String xpath7;
    //    路径位置
    private Integer xpath7Location;
//    长字符串值，用于存储较长的字符串信息
    private String xstringLongValue;
//    短字符串值，用于存储较短的字符串信息
    private String xstringShortValue;
//    时间值，存储时间信息，但不包含日期
    private LocalTime xtimeValue;


}
