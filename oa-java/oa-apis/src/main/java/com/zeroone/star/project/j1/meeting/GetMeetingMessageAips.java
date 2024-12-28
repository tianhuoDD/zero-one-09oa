package com.zeroone.star.project.j1.meeting;

import com.zeroone.star.project.dto.j1.meeting.getting.InvitedMeetingInfoDTO;
import com.zeroone.star.project.dto.j1.meeting.getting.MySponsorMeetingInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.meeting.getting.InvitedMeetingInfoVO;
import com.zeroone.star.project.vo.j1.meeting.getting.MySponsorMeetingInfoVO;

import java.util.List;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.project.j1.meeting.getting
 * @Author: dashuai
 * @CreateTime: 2024-10-21  13:09
 * @Description: 获取会议信息有关接口
 * @Version: 1.0
 */
public interface GetMeetingMessageAips {
    /**
     * @description:
     * @author: dashuai
     * @date: 2024/10/21 13:11
     * @param: [personId] 登录人id
     * @return: List<JsonVO<MySponsorMeetingInfoVO>> 我发起的会议对应的信息列表
     **/
    JsonVO<List<MySponsorMeetingInfoDTO>> queryMySponsorMeetingInfo(String personId);

    /**
     * @description:
     * @author: dashuai
     * @date: 2024/10/21 13:13
     * @param: [personId] 登录人id
     * @return: List<JsonVO<InvitedMeetingInfoVO>> 我邀请的会议对应的信息列表
     **/
    JsonVO<List<InvitedMeetingInfoDTO>> queryInvitedMeetingInfo(String personId);
}
