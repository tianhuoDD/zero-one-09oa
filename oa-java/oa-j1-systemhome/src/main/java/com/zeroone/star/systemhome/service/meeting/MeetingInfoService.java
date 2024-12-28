package com.zeroone.star.systemhome.service.meeting;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j1.meeting.getting.InvitedMeetingInfoDTO;
import com.zeroone.star.project.dto.j1.meeting.getting.MySponsorMeetingInfoDTO;
import com.zeroone.star.systemhome.entity.file.MtMeeting;

import java.util.List;

/**
 * @description: 获取会议信息service层接口
 * @author: dashuai
 * @date: 2024/10/24 11:01
 **/
public interface MeetingInfoService extends IService<MtMeeting> {
    /**
     * @description: 获取我发起的会议信息
     * @author: dashuai
     * @date: 2024/10/24 11:04
     * @param: [id] 登录人id
     * @return: List<MySponsorMeetingInfoDTO> 返回结果
     **/
    List<MySponsorMeetingInfoDTO> listMSMI(String id);

    /**
     * @description: 获取我邀请的会议信息
     * @author: dashuai
     * @date: 2024/10/24 11:05
     * @param: [id] 登录人id
     * @return: List<InvitedMeetingInfoDTO> 返回结果
     **/
    List<InvitedMeetingInfoDTO> listIMI(String id);
}
