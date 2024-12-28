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
@TableName("cal_event_manageablepersonlist")
public class CalEventManageablepersonlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventXid;

    private String xmanageablePersonList;

    private Integer xorderColumn;


}
