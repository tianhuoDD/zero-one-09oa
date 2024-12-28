package com.zeroone.star.meetingmanagement.controller;


import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.meetingmanagement.entity.MtMeeting;
import com.zeroone.star.meetingmanagement.service.IMtMeetingService;
import com.zeroone.star.project.dto.meetingmangement.MeetingDTO;
import com.zeroone.star.project.dto.j7.meeting.MeetingDto;
import com.zeroone.star.project.j7.meetingmanagement.MeetingManagementApis;
import com.zeroone.star.project.query.meeting.MeetingQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.meetingmanagement.service.IMtMeetingAcceptpersonlistService;
import com.zeroone.star.meetingmanagement.service.IMtMeetingRejectpersonlistService;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.annotation.Resource;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@RestController
@Api(tags = "会议管理")
@RequestMapping("/mt-meeting")
public class MtMeetingController implements MeetingManagementApis {
    @Resource
    private IMtMeetingService mtMeetingService;
    @Resource
    private IMtMeetingAcceptpersonlistService iMtMeetingAcceptpersonlistService;
    @Resource
    private IMtMeetingRejectpersonlistService iMtMeetingRejectpersonlistService;

    @ApiOperation("更新会议")
    @PostMapping("/updateMeeting")
    @Override
    public JsonVO updateMeeting(@RequestBody MeetingDTO meetingDTO){
        MtMeeting mtMeeting = new MtMeeting();
        BeanUtils.copyProperties(meetingDTO,mtMeeting);
        mtMeetingService.update(mtMeeting,new UpdateWrapper<MtMeeting>().eq("xid",mtMeeting.getXid()));
        return JsonVO.success("更新成功");
    }
    @GetMapping("/cancel")
    @ApiOperation("取消会议")
    public JsonVO<Long> cancelMeeting(String xId) {
        return null;
    }



    @PostMapping("/add")
    @ApiOperation("新增会议")
    public JsonVO<Long> addMeeting(@RequestBody MeetingDto dto) {
        return null;
    }

    @ApiOperation("获取会议详情")
    @GetMapping("/getMeeting")
    @Override
    public JsonVO getMeeting(String xid) {
        return JsonVO.success(mtMeetingService.getById(xid));
    }



    @PostMapping("/accept-meeting")
    @ApiOperation("接受会议")
    public JsonVO acceptMeeting(String meetingId) throws Exception {
        boolean b = iMtMeetingAcceptpersonlistService.acceptMeeting(meetingId);
        if (b)
        return JsonVO.success(null);
        return JsonVO.fail(null);
    }

    @PostMapping("/complete-meeting")
    @ApiOperation("结束会议")
    public JsonVO completeMeeting(String meetingId) throws Exception {
        boolean b = mtMeetingService.completeMeeting(meetingId);
        if (b)
            return JsonVO.success(null);
        return JsonVO.fail(null);
    }

    @PostMapping("/reject-meeting")
    @ApiOperation("拒绝会议")
    public JsonVO rejectMeeting(String meetingId) throws Exception {
        boolean b = iMtMeetingRejectpersonlistService.rejectMeeting(meetingId);
        if (b)
            return JsonVO.success(null);
        return JsonVO.fail(null);
    }


    @GetMapping("query-all")
    @ApiOperation(value = "分页查询")
    @Override
    public JsonVO QueryListMeeting(MeetingQuery condition) {
        return JsonVO.success(mtMeetingService.listAllMt(condition));
    }
    @GetMapping("query-by-xid")
    @ApiOperation(value = "根据xid查询")
    @Override
    public JsonVO QueryGetMeeting(int xid) {
        return null;
    }
}

