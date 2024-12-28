package com.zeroone.star.meetingmanagement.service;

import com.zeroone.star.meetingmanagement.entity.MtMeetingAcceptpersonlist;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.meetingmanagement.mapper.MtMeetingMapper;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 渺尘
 * @since 2024-10-19
 */
public interface IMtMeetingAcceptpersonlistService extends IService<MtMeetingAcceptpersonlist> {

    boolean acceptMeeting(String meetingId) throws Exception;

}
