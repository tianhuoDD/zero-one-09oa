package com.zeroone.star.calmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;

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
@Data
@TableName("cal_calendar_followers")
public class CalCalendarFollowers implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableField("CALENDAR_XID")
    @ApiModelProperty(value = "日历ID", example = "8d33cc48-1abf-4f83-b4a5-fa52f96956aa")
    private String CALENDAR_XID;

    @TableField("xfollowers")
    @ApiModelProperty(value = "关注人", example = "xadmin")
    private String xfollowers;

    @TableField("xorderColumn")
    @ApiModelProperty(value = "排序字段", example = "1")
    private Integer xorderColumn;


}
