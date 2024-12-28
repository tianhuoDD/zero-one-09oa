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
@TableName("cal_event_manageablepersonlist")
public class CalEventManageablepersonlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventXid;

    private String xmanageablePersonList;

    private Integer xorderColumn;


}
