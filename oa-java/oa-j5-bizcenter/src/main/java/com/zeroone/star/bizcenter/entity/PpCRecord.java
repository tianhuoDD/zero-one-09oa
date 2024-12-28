package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 流程记录实体类，映射到数据库中的pp_c_record表
 */
@Data
@TableName("pp_c_record")
public class PpCRecord {

    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid; // 主键ID；

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime; // 创建时间；

    @TableField("xsequence")
    private String xsequence; // 序列；

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime; // 更新时间；

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor; // 分发因子；

    @TableField("xapplication")
    private String xapplication; // 应用标识；

    @TableField("xcompleted")
    private Boolean xcompleted; // 是否完成；

    @TableField("xdisplay")
    private Boolean xdisplay; // 是否显示；

    @TableField("xfromActivity")
    private String xfromActivity; // 来源活动；

    @TableField("xfromActivityAlias")
    private String xfromActivityAlias; // 来源活动别名；

    @TableField("xfromActivityName")
    private String xfromActivityName; // 来源活动名称；

    @TableField("xfromActivityToken")
    private String xfromActivityToken; // 来源活动令牌；

    @TableField("xfromActivityType")
    private String xfromActivityType; // 来源活动类型；

    @TableField("xidentity")
    private String xidentity; // 身份标识；

    @TableField("xjob")
    private String xjob; // 工作标识；

    @TableField("xorder")
    private Long xorder; // 排序；

    @TableField("xperson")
    private String xperson; // 人员标识；

    @TableField("xprocess")
    private String xprocess; // 流程标识；

    @TableField("xproperties")
    private String xproperties; // 属性；

    @TableField("xrecordTime")
    private LocalDateTime xrecordTime; // 记录时间；

    @TableField("xtype")
    private String xtype; // 类型；

    @TableField("xunit")
    private String xunit; // 单位；

    @TableField("xwork")
    private String xwork; // 工作标识；

    @TableField("xworkCompleted")
    private String xworkCompleted; // 工作完成标识；
}