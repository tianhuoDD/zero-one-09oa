package com.zeroone.star.systemhome.controller;

import com.zeroone.star.project.dto.j1.meeting.getting.InvitedMeetingInfoDTO;
import com.zeroone.star.project.dto.j1.meeting.getting.MySponsorMeetingInfoDTO;
import com.zeroone.star.project.j1.meeting.GetMeetingMessageAips;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemhome.service.impl.meeting.MeetingInfoImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.systemhome.controller
 * @Author: dashuai
 * @CreateTime: 2024-10-21  19:23
 * @Description: 获取会议信息相关接口
 * @Version: 1.0
 */
@RestController
@RequestMapping("/systemhome/meeting")
@Api(tags = "获取会议信息相关接口")
@RequiredArgsConstructor
public class MeetingController implements GetMeetingMessageAips {

    private final MeetingInfoImpl meetingInfo;

    /**
     * @description: 获取我发起的会议相关信息
     * @author: dashuai
     * @date: 2024/10/21 19:31
     * @param: [PersonId] 登录人id
     * @return: List<JsonVO<MySponsorMeetingInfoVO>> 我发起的会议相关信息列表
     **/
    @Override
    @ApiOperation(value = "获取我发起的会议相关信息")
    @GetMapping("query-MySponsorMeetingInfo")
    public JsonVO<List<MySponsorMeetingInfoDTO>> queryMySponsorMeetingInfo(String PersonId) {
        return JsonVO.success(meetingInfo.listMSMI(PersonId));
    }

    /**
     * @description: 获取被邀请的会议相关信息
     * @author: dashuai
     * @date: 2024/10/21 19:33
     * @param: [PersonId] 登录人id
     * @return: List<JsonVO<InvitedMeetingInfoVO>> 被邀请的会议相关信息列表
     **/
    @Override
    @ApiOperation(value = "获取被邀请的会议相关信息")
    @GetMapping("query-InvitedMeetingInfo")
    public JsonVO<List<InvitedMeetingInfoDTO>> queryInvitedMeetingInfo(String PersonId) {
        return JsonVO.success(meetingInfo.listIMI(PersonId));
    }
}
