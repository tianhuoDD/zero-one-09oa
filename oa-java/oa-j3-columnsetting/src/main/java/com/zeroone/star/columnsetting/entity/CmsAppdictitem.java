package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
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
 *
 * </p>
 *
 * @author luo
 * @since 2024-10-20
 */
@Getter
@Setter
@TableName("cms_appdictitem")
public class CmsAppdictitem implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField(value = "xsequence")
    private String xsequence;

    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField(value = "xappId")
    private String xappId;

    @TableField(value = "xbooleanValue")
    private Boolean xbooleanValue;

    @TableField(value = "xbundle")
    private String xbundle;

    @TableField(value = "xdateTimeValue")
    private LocalDateTime xdateTimeValue;

    @TableField(value = "xdateValue")
    private LocalDate xdateValue;

    @TableField(value = "xitemCategory")
    private String xitemCategory;

    @TableField(value = "xitemPrimitiveType")
    private String xitemPrimitiveType;

    @TableField(value = "xitemStringValueType")
    private String xitemStringValueType;

    @TableField(value = "xitemType")
    private String xitemType;

    @TableField(value = "xnumberValue")
    private Double xnumberValue;

    @TableField(value = "xpath0")
    private String xpath0;

    @TableField(value = "xpath0Location")
    private Integer xpath0Location;

    @TableField(value = "xpath1")
    private String xpath1;

    @TableField(value = "xpath1Location")
    private Integer xpath1Location;

    @TableField(value = "xpath2")
    private String xpath2;

    @TableField(value = "xpath2Location")
    private Integer xpath2Location;

    @TableField(value = "xpath3")
    private String xpath3;

    @TableField(value = "xpath3Location")
    private Integer xpath3Location;

    @TableField(value = "xpath4")
    private String xpath4;

    @TableField(value = "xpath4Location")
    private Integer xpath4Location;

    @TableField(value = "xpath5")
    private String xpath5;

    @TableField(value = "xpath5Location")
    private Integer xpath5Location;

    @TableField(value = "xpath6")
    private String xpath6;

    @TableField(value = "xpath6Location")
    private Integer xpath6Location;

    @TableField(value = "xpath7")
    private String xpath7;

    @TableField(value = "xpath7Location")
    private Integer xpath7Location;

    @TableField(value = "xstringLongValue")
    private String xstringLongValue;

    @TableField(value = "xstringShortValue")
    private String xstringShortValue;

    @TableField(value = "xtimeValue")
    private LocalTime xtimeValue;


}
