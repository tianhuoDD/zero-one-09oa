package com.zeroone.star.calmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.calmanager.entity.CalCalendarFollowers;
import com.zeroone.star.calmanager.mapper.CalCalendarFollowersMapper;
import com.zeroone.star.calmanager.service.ICalCalendarFollowersService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.j6.calendar.ActionFollowCalendarVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
@Service
public class CalCalendarFollowersServiceImpl extends ServiceImpl<CalCalendarFollowersMapper, CalCalendarFollowers> implements ICalCalendarFollowersService {

    @Autowired
    private CalCalendarFollowersMapper calCalendarFollowersMapper;

    @Override
    @Transactional
    public ActionFollowCalendarVO followCalendar(String calendarId, String userId) {
        // 参数校验
        if (calendarId == null  || userId == null || calendarId.trim().isEmpty() || userId.trim().isEmpty()) {
            throw new IllegalArgumentException("日历ID或者userID不能为空");
        }
        QueryWrapper<CalCalendarFollowers> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("CALENDAR_XID", calendarId);
        List<CalCalendarFollowers> calendarList = calCalendarFollowersMapper.selectList(queryWrapper);
        if (calendarList.isEmpty()) {
            return ActionFollowCalendarVO.builder()
                    .followStatus(false)
                    .message("日历不存在")
                    .build();
        }

        // 检查是否是自己的日历
        boolean isOwner = calendarList.stream()
                .anyMatch(entry -> entry.getXfollowers().equals(userId));
        if (isOwner) {
            return ActionFollowCalendarVO.builder()
                    .followStatus(false)
                    .message("不能关注自己的日历/或日历已经关注")
                    .build();
        }


        /*// 检查是否已经关注
        QueryWrapper<CalCalendarFollowers> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("CALENDAR_XID", calendarId).eq("xfollowers",userId);
        boolean exists = calCalendarFollowersMapper.selectCount(queryWrapper) > 0;
        if (exists) {
            ActionFollowCalendarVO actionFollowCalendarVO = new ActionFollowCalendarVO();
            actionFollowCalendarVO.setFollowStatus(false);
            actionFollowCalendarVO.setMessage("不能关注自己日历");
            return actionFollowCalendarVO;
        }*/

        // 添加关注记录
        CalCalendarFollowers followers = new CalCalendarFollowers();
        followers.setCALENDAR_XID(calendarId);
        followers.setXfollowers(userId);
        followers.setXorderColumn(0);
        boolean followSuccess = save(followers);

        // 构造响应VO
        return ActionFollowCalendarVO.builder()
                .followStatus(followSuccess)
                .message(followSuccess ? "关注成功" : "关注失败")
                .build();

        /*// 添加关注记录
        CalCalendarFollowers followers = new CalCalendarFollowers();
        followers.setCALENDAR_XID(calendarId);
        followers.setXfollowers(userId);

        followers.setXorderColumn(0);
        boolean followSuccess = save(followers);

        // 构造响应VO
        ActionFollowCalendarVO actionFollowCalendarVO = new ActionFollowCalendarVO();
        actionFollowCalendarVO.setFollowStatus(followSuccess);
        actionFollowCalendarVO.setMessage(followSuccess ? "关注成功" : "关注失败");
        return actionFollowCalendarVO;*/
    }

    @Override
    @Transactional
    public ActionFollowCalendarVO unfollowCalendar(String calendarId, String userId) {


        // 参数校验
        if (calendarId == null  || userId == null || calendarId.trim().isEmpty() || userId.trim().isEmpty()) {
            throw new IllegalArgumentException("日历ID与userID不能为空");
        }

        // 删除关注记录
        QueryWrapper<CalCalendarFollowers> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("CALENDAR_XID", calendarId).eq("xfollowers", userId);
        int rows = calCalendarFollowersMapper.delete(queryWrapper);
        boolean unfollowSuccess = rows > 0;
        // 构造响应VO
        return ActionFollowCalendarVO.builder()
                .followStatus(unfollowSuccess)
                .message(unfollowSuccess ? "取消关注成功" : "取消关注失败，找不到该用户与该日历的关注信息")
                .build();
    }

        // 参数校验
       /* if (calendarId == null || calendarId.trim().isEmpty() || userId == null) {
            throw new IllegalArgumentException("日历ID与userID不能为空");
        }

        // 删除关注记录
        QueryWrapper<CalCalendarFollowers> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("CALENDAR_XID", calendarId).eq("xfollowers", userId);
        int rows = calCalendarFollowersMapper.delete(queryWrapper);
        boolean unfollowSuccess = rows > 0;

        // 构造响应VO
        ActionFollowCalendarVO actionFollowCalendarVO = new ActionFollowCalendarVO();
        actionFollowCalendarVO.setFollowStatus(unfollowSuccess);
        actionFollowCalendarVO.setMessage(unfollowSuccess ? "取消关注成功" : "取消关注失败");
        return ActionFollowCalendarVO.builder().followStatus();
    }*/
}
