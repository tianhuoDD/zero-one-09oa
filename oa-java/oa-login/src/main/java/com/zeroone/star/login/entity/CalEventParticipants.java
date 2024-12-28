package com.zeroone.star.login.entity;

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
@TableName("cal_event_participants")
public class CalEventParticipants implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventXid;

    private String xparticipants;

    private Integer xorderColumn;


}
