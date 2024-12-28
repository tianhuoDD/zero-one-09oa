package com.zeroone.star.project.j7.meetingmanagement;

import com.zeroone.star.project.dto.meetingmangement.CheckinDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface CheckinPersonListApis {
    /**
     * 会议签到
     * @param checkinDTO 签到会议
     * @return 新增数据唯一编号
     */
    JsonVO<String> addPerson(CheckinDTO checkinDTO);
}
