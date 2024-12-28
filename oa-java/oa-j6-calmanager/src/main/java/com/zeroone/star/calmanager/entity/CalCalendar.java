package com.zeroone.star.calmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 *
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("cal_calendar")
@Data
public class CalCalendar implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableField("xid") // 指定数据库字段名
    private String xid;

    @TableField("xcreateTime") // 指定数据库字段名
    private LocalDateTime xcreateTime;

    @TableField("xsequence") // 指定数据库字段名
    private String xsequence;

    @TableField("xupdateTime") // 指定数据库字段名
    private LocalDateTime xupdateTime;

    @TableField("xdistributeFactor") // 指定数据库字段名
    private Integer xdistributeFactor;

    @TableField("xcolor") // 指定数据库字段名
    private String xcolor;


    @TableField("xcreateor") // 指定数据库字段名
    private String xcreateor;


    @TableField("xdescription") // 指定数据库字段名
    private String xdescription;


    @TableField("xisPublic") // 指定数据库字段名
    private Boolean xisPublic;


    @TableField("xname") // 指定数据库字段名
    private String xname;


    @TableField("xsource") // 指定数据库字段名
    private String xsource;


    @TableField("xstatus") // 指定数据库字段名
    private String xstatus;


    @TableField("xtarget") // 指定数据库字段名
    private String xtarget;

    @ApiModelProperty(value = "类型", example = "PERSON")

    @TableField("xtype") // 指定数据库字段名
    private String xtype;

}
