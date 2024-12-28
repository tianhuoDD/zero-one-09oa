package com.zeroone.star.systemhome.mapper.meeting;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j1.meeting.getting.InvitedMeetingInfoDTO;
import com.zeroone.star.project.dto.j1.meeting.getting.MySponsorMeetingInfoDTO;
import com.zeroone.star.systemhome.entity.file.MtMeeting;
import org.apache.ibatis.annotations.Mapper;

import java.time.LocalDateTime;
import java.util.List;

@Mapper
public interface MeetingInfoMapper extends BaseMapper<MtMeeting> {
    List<MySponsorMeetingInfoDTO> selectMSMI(String id, String currentTime);

    List<InvitedMeetingInfoDTO> selectIMI(String id, String currentTime);
}
