package com.zeroone.star.meetingmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author caifeng
 * @since 2024-10-24
 */
@Getter
@Setter
@TableName("mt_meeting_checkinpersonlist")
public class MtMeetingCheckinpersonlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String meetingXid;

    private String xcheckinPersonList;

    private Integer xorderColumn;


}
