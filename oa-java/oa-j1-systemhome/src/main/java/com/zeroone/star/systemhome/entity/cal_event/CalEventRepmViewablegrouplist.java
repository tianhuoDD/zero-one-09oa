package com.zeroone.star.systemhome.entity.cal_event;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author 李云毅
 * @since 2024-10-26
 */
@Getter
@Setter
@TableName("cal_event_repm_viewablegrouplist")
public class CalEventRepmViewablegrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String calendarEventrepeatmasterXid;

    private String xviewableGroupList;

    private Integer xorderColumn;


}
