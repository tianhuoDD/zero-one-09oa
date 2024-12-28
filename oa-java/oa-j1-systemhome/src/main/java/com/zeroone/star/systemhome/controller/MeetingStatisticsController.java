package com.zeroone.star.systemhome.controller;

import com.zeroone.star.project.j1.system.home.MeetingStatisticsApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.system.home.MeetingStatisticsInfoVo;
import com.zeroone.star.systemhome.service.impl.MeetingStatisticsServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：会议统计controller层
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
@RestController
@RequestMapping("systemhome")
@Api(tags = "会议统计")
public class MeetingStatisticsController implements MeetingStatisticsApis {
    @Autowired
    private MeetingStatisticsServiceImpl meetingStatisticsImpl;

    /**
     * 根据用户id，获得会议统计的部分信息，包括会议主题，会议开始时间，会议结束时间，会议室建筑名，会议室名字
     * @param id 用户id
     * @return 会议统计的相关数据，包括会议主题，会议开始时间，会议结束时间，会议室建筑名，会议室名字
     */
    @GetMapping("query-meeting-info")
    @Override
    @ApiOperation(value = "获取会议统计相关信息")
    public JsonVO<List<MeetingStatisticsInfoVo>> queryMeetingInfo(String id) {
        //调用下层
        List<MeetingStatisticsInfoVo> result = meetingStatisticsImpl.getMeetingInfo(id);
        //封装
        return JsonVO.success(result);
    }
}
