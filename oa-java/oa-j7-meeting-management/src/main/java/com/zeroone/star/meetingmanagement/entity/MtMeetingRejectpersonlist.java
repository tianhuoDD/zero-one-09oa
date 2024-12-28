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
@TableName("mt_meeting_rejectpersonlist")
public class MtMeetingRejectpersonlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 会议id
     */
    private String meetingXid;

    /**
     * 拒绝人列表
     */
    private String xrejectPersonList;

    /**
     * 排序栏
     */
    private Integer xorderColumn;


}
