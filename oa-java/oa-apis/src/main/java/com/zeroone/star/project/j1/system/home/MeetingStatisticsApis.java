package com.zeroone.star.project.j1.system.home;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.system.home.MeetingStatisticsInfoVo;

import java.util.List;

/**
 * <p>
 * 描述：会议统计相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
public interface MeetingStatisticsApis {
    /**
     * 获取我的会议信息
     * @param id 用户id
     * @return 获取到的我的会议信息
     */
    public JsonVO<List<MeetingStatisticsInfoVo>> queryMeetingInfo(String id);
}
