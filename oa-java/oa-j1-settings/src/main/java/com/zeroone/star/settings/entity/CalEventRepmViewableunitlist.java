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
@TableName("cal_event_repm_viewableunitlist")
public class CalEventRepmViewableunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventrepeatmasterXid;

    private String xviewableUnitList;

    private Integer xorderColumn;


}
