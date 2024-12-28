package com.zeroone.star.calmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
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
@TableName("cal_calendar_manageablepersonlist")
public class CalCalendarManageablepersonlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 日历唯一标识符
     */
    @TableField("CALENDAR_XID")
    private String calendarXid;

    /**
     * 可管理的人员列表，存储用户的 distinguishedName
     */
    @TableField("xmanageablePersonList")
    private String xmanageablePersonList;

    /**
     * 排序列，用于管理者的顺序
     */
    @TableField("xorderColumn")
    private Integer xorderColumn;
}
