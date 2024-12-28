package com.zeroone.star.meetingmanagement.service;

import com.zeroone.star.meetingmanagement.entity.MtMeetingRejectpersonlist;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 渺尘
 * @since 2024-10-19
 */
public interface IMtMeetingRejectpersonlistService extends IService<MtMeetingRejectpersonlist> {

    boolean rejectMeeting(String meetingId) throws Exception;

}
