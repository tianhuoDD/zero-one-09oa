package com.zeroone.star.meetingmanagement.service.impl;

import com.zeroone.star.meetingmanagement.entity.MtMeetingAcceptpersonlist;
import com.zeroone.star.meetingmanagement.mapper.MtMeetingAcceptpersonlistMapper;
import com.zeroone.star.meetingmanagement.service.IMtMeetingAcceptpersonlistService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.zeroone.star.meetingmanagement.mapper.MtMeetingMapper;
import com.zeroone.star.meetingmanagement.service.IMtMeetingAcceptpersonlistService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalTime;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 渺尘
 * @since 2024-10-19
 */
@Service
public class MtMeetingAcceptpersonlistServiceImpl extends ServiceImpl<MtMeetingAcceptpersonlistMapper, MtMeetingAcceptpersonlist> implements IMtMeetingAcceptpersonlistService {
    @Resource
    private MtMeetingMapper mtMapper;
    @Autowired
    private UserHolder userHolder;
    @Override
    public boolean acceptMeeting(String meetingId) throws Exception {
        //判断会议是否结束
        LocalTime actualCompletedTime = mtMapper.getActualCompletedTime(meetingId);
        if (actualCompletedTime == null)
        {
            //真正结束时间为空表示未结束，接受成功，可以入会
            //1.获取用户名
            UserDTO currentUser = userHolder.getCurrentUser();
            String username = currentUser.getUsername();
            //2.保存信息
            MtMeetingAcceptpersonlist mtac = new MtMeetingAcceptpersonlist();
            mtac.setMeetingXid(meetingId);
            mtac.setXacceptPersonList(username);
            save(mtac);
            return true;
        }
        //会议结束，入会失败
        return false;
    }
}
