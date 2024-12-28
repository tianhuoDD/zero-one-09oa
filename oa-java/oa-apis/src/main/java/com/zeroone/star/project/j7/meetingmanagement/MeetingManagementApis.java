package com.zeroone.star.project.j7.meetingmanagement;

import com.zeroone.star.project.dto.j7.meeting.MeetingDto;
import com.zeroone.star.project.dto.meetingmangement.MeetingDTO;
import com.zeroone.star.project.query.meeting.MeetingQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface MeetingManagementApis {

    /**
     * 修改会议室
     * @return 封装对象

     */
    public JsonVO updateMeeting(MeetingDTO meetingDTO);

    /**
     * 取消会议
     * @param xid
     * @return
     */
    public JsonVO<Long> cancelMeeting(String xid);

    /**
     * 新增会议
     * @return
     */
    public JsonVO<Long> addMeeting(MeetingDto dto);

    /**
     * 获取会议详情
     * @param xid
     * @return
     */
    public JsonVO getMeeting(String xid);


    /**
     * 根据xid查询
     * @param xid
     * @return
     */
    public JsonVO QueryGetMeeting(int xid);

    /**
     * 分页查询
     * @param condition
     * @return
     */
    public JsonVO QueryListMeeting(MeetingQuery condition);

}
