package com.zeroone.star.meetingmanagement.service;

import com.zeroone.star.meetingmanagement.entity.MtMeeting;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.meetingmangement.MtDTO;
import com.zeroone.star.project.query.meeting.MeetingQuery;
import com.zeroone.star.project.query.meetingroom.MeetingRoomQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author ydp
 * @since 2024-10-21
 */
public interface IMtMeetingService extends IService<MtMeeting> {
    /**
     * 分页查询数据
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<MtDTO> listAllMt(MeetingQuery query);
    /**
     * 感觉id查询数据
     * @param xid 查询编号
     * @return 查询结果
     */
    MtDTO getByXid(Integer xid);
    boolean completeMeeting(String meetingId) throws Exception;
}
