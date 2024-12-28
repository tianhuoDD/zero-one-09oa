package com.zeroone.star.systemhome.entity.file;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 会议接受人员名单实体类
 * </p>
 *
 * @author j1.rabbit
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("mt_meeting_acceptpersonlist")
public class MtMeetingAcceptPersonList implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value="MEETING_XID")
    private String meetingXid;

    private String xacceptPersonList;

    private Integer xorderColumn;

}
