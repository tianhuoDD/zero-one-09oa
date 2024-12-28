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
@TableName("cal_calendar_viewablegrouplist")
public class CalCalendarViewablegrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 日历唯一标识符
     */
    @TableField("CALENDAR_XID")
    private String calendarXid;

    /**
     * 可见的群组列表，存储群组的 distinguishedName
     */
    @TableField("xviewableGroupList")
    private String xviewableGroupList;

    /**
     * 排序列，用于群组的顺序
     */
    @TableField("xorderColumn")
    private Integer xorderColumn;
}
