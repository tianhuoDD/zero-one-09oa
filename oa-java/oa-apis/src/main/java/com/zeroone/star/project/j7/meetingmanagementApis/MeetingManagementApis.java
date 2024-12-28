package com.zeroone.star.project.j7.meetingmanagementApis;

import com.zeroone.star.project.vo.JsonVO;

public interface MeetingManagementApis {
    public JsonVO acceptMeeting(String meetingId) throws Exception;
    public JsonVO completeMeeting(String meetingId) throws Exception;

    public JsonVO rejectMeeting(String meetingId) throws Exception;
}
