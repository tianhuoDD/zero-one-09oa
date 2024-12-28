package com.zeroone.star.settings.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 
 * </p>
 *
 * @author han
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("cal_event_viewableunitlist")
public class CalEventViewableunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventXid;

    private String xviewableUnitList;

    private Integer xorderColumn;


}
