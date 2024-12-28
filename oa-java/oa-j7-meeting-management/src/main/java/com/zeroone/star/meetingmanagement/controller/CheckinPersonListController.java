package com.zeroone.star.meetingmanagement.controller;

import com.zeroone.star.meetingmanagement.service.IMtMeetingCheckinpersonlistService;
import com.zeroone.star.project.dto.meetingmangement.CheckinDTO;
import com.zeroone.star.project.j7.meetingmanagement.CheckinPersonListApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("checkin")
@Api(tags = "签到人员管理")
@Validated
public class CheckinPersonListController implements CheckinPersonListApis {

    @Resource
    IMtMeetingCheckinpersonlistService mtMeetingCheckinpersonlistService;

    @Override
    @ApiOperation("添加签到人员")
    @PostMapping("add")
    public JsonVO<String> addPerson(@Validated CheckinDTO checkinDTO) {
        return mtMeetingCheckinpersonlistService.addCheckinPerson(checkinDTO);
    }
}
