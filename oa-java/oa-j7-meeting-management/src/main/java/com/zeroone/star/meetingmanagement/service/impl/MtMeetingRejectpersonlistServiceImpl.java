package com.zeroone.star.meetingmanagement.service.impl;

import com.zeroone.star.meetingmanagement.entity.MtMeetingAcceptpersonlist;
import com.zeroone.star.meetingmanagement.entity.MtMeetingRejectpersonlist;
import com.zeroone.star.meetingmanagement.mapper.MtMeetingRejectpersonlistMapper;
import com.zeroone.star.meetingmanagement.service.IMtMeetingRejectpersonlistService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 渺尘
 * @since 2024-10-19
 */
@Service
public class MtMeetingRejectpersonlistServiceImpl extends ServiceImpl<MtMeetingRejectpersonlistMapper, MtMeetingRejectpersonlist> implements IMtMeetingRejectpersonlistService {
    @Resource
    private UserHolder userHolder;
    @Override
    public boolean rejectMeeting(String meetingId) throws Exception {

        //1.获取用户名
        UserDTO currentUser = userHolder.getCurrentUser();
        String username = currentUser.getUsername();
        //2.保存信息
        MtMeetingRejectpersonlist mtac = new MtMeetingRejectpersonlist();
        mtac.setMeetingXid(meetingId);
        mtac.setXrejectPersonList(username);
        save(mtac);
        return true;
    }
}
