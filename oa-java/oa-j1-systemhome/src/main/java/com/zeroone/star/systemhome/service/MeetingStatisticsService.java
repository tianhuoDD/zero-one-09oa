package com.zeroone.star.systemhome.service;

import com.zeroone.star.project.vo.j1.system.home.MeetingStatisticsInfoVo;

import java.util.List;

/**
 * <p>
 * 描述：会议统计service接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
public interface MeetingStatisticsService {

    /**
     * 根据用户id，获得会议统计的部分信息，包括会议主题，会议开始时间，会议结束时间，会议室建筑名，会议室名字
     * @param id 用户id
     * @return 会议统计的相关数据，包括会议主题，会议开始时间，会议结束时间，会议室建筑名，会议室名字
     */
    public List<MeetingStatisticsInfoVo> getMeetingInfo(String id);
}
