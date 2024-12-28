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
 * @author 渺尘
 * @since 2024-10-19
 */
@Getter
@Setter
@TableName("mt_meeting_acceptpersonlist")
public class MtMeetingAcceptpersonlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 会议id
     */
    private String meetingXid;

    /**
     * 接受人员列表
     */
    private String xacceptPersonList;

    /**
     * 订单栏(排序列？)
     */
    private Integer xorderColumn;


}
