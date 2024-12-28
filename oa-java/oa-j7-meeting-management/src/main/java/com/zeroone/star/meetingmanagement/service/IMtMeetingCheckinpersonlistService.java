package com.zeroone.star.meetingmanagement.service;

import com.zeroone.star.meetingmanagement.entity.MtMeetingCheckinpersonlist;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.meetingmangement.CheckinDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author caifeng
 * @since 2024-10-24
 */
public interface IMtMeetingCheckinpersonlistService extends IService<MtMeetingCheckinpersonlist> {
    JsonVO<String> addCheckinPerson(CheckinDTO checkinDTO);
}
