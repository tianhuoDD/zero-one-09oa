package com.zeroone.star.meetingmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.meetingmanagement.entity.MtMeeting;
import com.zeroone.star.meetingmanagement.mapper.MtMeetingMapper;
import com.zeroone.star.meetingmanagement.service.IMtMeetingService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.meetingmangement.MtDTO;
import com.zeroone.star.project.query.meeting.MeetingQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import java.sql.Wrapper;
import java.time.LocalTime;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsMtMapper{
    /**
     * 将MtRoomDO转换为MtRoomDTO
     * @param mt do对象
     * @return 转换结果
     */
    MtDTO MtRoom2MtRoomDTO(MtMeeting mt);
}

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author ydp
 * @since 2024-10-21
 */
@Service
public class MtMeetingServiceImpl extends ServiceImpl<MtMeetingMapper, MtMeeting> implements IMtMeetingService {
    @Resource
    MsMtMapper msMtMapper;
    @Override
    public PageDTO<MtDTO> listAllMt(MeetingQuery query) {
        // 构建分页对象
        Page<MtMeeting> page = new Page<>(query.getPageIndex(),query.getPageSize());
        // 构建查询条件
        QueryWrapper<MtMeeting> queryWrapper = new QueryWrapper<>();
        queryWrapper.like("xauditor",query.getXauditor());
        // 执行查询
        Page<MtMeeting> result = baseMapper.selectPage(page, queryWrapper);
        // 转换结果
        return PageDTO.create(result,msMtMapper::MtRoom2MtRoomDTO);
    }

    @Override
    public MtDTO getByXid(Integer xid) {
        MtMeeting result = baseMapper.selectById(xid);
        if(result != null){
            return msMtMapper.MtRoom2MtRoomDTO(result);
        }
        return null;
    }
    @Override
    public boolean completeMeeting(String meetingId) throws Exception {
        //获取当前时间
        LocalTime now = LocalTime.now();
        UpdateWrapper<MtMeeting> wrapper =  new UpdateWrapper<MtMeeting>();
        wrapper.eq("xid",meetingId);
        //更新结束时间
        wrapper.set("xactualCompletedTime",now);
        return true;
    }
}
