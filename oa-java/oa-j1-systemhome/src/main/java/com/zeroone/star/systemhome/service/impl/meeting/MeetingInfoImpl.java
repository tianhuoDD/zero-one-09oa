package com.zeroone.star.systemhome.service.impl.meeting;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j1.meeting.getting.InvitedMeetingInfoDTO;
import com.zeroone.star.project.dto.j1.meeting.getting.MySponsorMeetingInfoDTO;
import com.zeroone.star.systemhome.entity.file.MtMeeting;
import com.zeroone.star.systemhome.mapper.meeting.MeetingInfoMapper;
import com.zeroone.star.systemhome.service.meeting.MeetingInfoService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.systemhome.service.impl
 * @Author: dashuai
 * @CreateTime: 2024-10-24  10:59
 * @Description: 获取会议有关信息
 * @Version: 1.0
 */
@Service
@RequiredArgsConstructor
public class MeetingInfoImpl extends ServiceImpl<MeetingInfoMapper, MtMeeting> implements MeetingInfoService{
    private final MeetingInfoMapper meetingInfoMapper;
    /**
     * @description: 获取我发起的会议信息
     * @author: dashuai
     * @date: 2024/10/24 11:34
     * @param: [id]
     * @return: List<MySponsorMeetingInfoDTO> 返回的结果
     **/
    @Override
    public List<MySponsorMeetingInfoDTO> listMSMI(String id) {
        LocalDateTime currentTime = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return meetingInfoMapper.selectMSMI(id, currentTime.format(formatter));
    }

    @Override
    public List<InvitedMeetingInfoDTO> listIMI(String id) {
        LocalDateTime currentTime = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return meetingInfoMapper.selectIMI(id, currentTime.format(formatter));
    }
}
