package com.zeroone.star.calmanager.entity;

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
@TableName("cal_event_viewableunitlist")
public class CalEventViewableunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventXid;

    private String xviewableUnitList;

    private Integer xorderColumn;


}
