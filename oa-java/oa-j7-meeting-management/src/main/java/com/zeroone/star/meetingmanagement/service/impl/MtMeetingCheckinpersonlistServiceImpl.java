package com.zeroone.star.meetingmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.zeroone.star.meetingmanagement.entity.MtMeetingCheckinpersonlist;
import com.zeroone.star.meetingmanagement.mapper.MtMeetingCheckinpersonlistMapper;
import com.zeroone.star.meetingmanagement.service.IMtMeetingCheckinpersonlistService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.meetingmangement.CheckinDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author caifeng
 * @since 2024-10-24
 */
@Service
public class MtMeetingCheckinpersonlistServiceImpl extends ServiceImpl<MtMeetingCheckinpersonlistMapper, MtMeetingCheckinpersonlist> implements IMtMeetingCheckinpersonlistService {

    @Resource
    MtMeetingCheckinpersonlistMapper mtMeetingCheckinpersonlistMapper;


    @Override
    public JsonVO<String> addCheckinPerson(CheckinDTO checkinDTO) {
        // TODO id
        int userId = 1;

        //构造查询条件
        LambdaQueryWrapper<MtMeetingCheckinpersonlist> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(MtMeetingCheckinpersonlist::getMeetingXid, checkinDTO.getMeetingXid());


        //原子性布尔值标志记录是否存在
        AtomicBoolean exists = new AtomicBoolean(true);

        //获取记录
        MtMeetingCheckinpersonlist mtMeetingCheckinpersonlist =
                Optional.ofNullable(mtMeetingCheckinpersonlistMapper.selectOne(queryWrapper))
                        .orElseGet(() -> {
                            //如果不存在则新建
                            MtMeetingCheckinpersonlist newList = new MtMeetingCheckinpersonlist();
                            newList.setMeetingXid(String.valueOf(checkinDTO.getMeetingXid()));
                            newList.setXcheckinPersonList(String.valueOf(new ArrayList<>()));
                            exists.set(false);
                            return newList;
                        });

        String personListStr = mtMeetingCheckinpersonlist.getXcheckinPersonList();


        //解析原有列表
        List<String> list = Arrays
                .asList(personListStr
                        .substring(1, personListStr.length() - 1)
                        .split(","));


        if (list.contains(String.valueOf(userId))) {
            return JsonVO.fail("您已经签到过了");
        }
        list.add(String.valueOf(userId));

        // TODO 排序

        //构造更新条件
        LambdaUpdateWrapper <MtMeetingCheckinpersonlist> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.eq(MtMeetingCheckinpersonlist::getMeetingXid, checkinDTO.getMeetingXid());

        //更新列表
        mtMeetingCheckinpersonlist.setXcheckinPersonList(String.valueOf(list));
        if (exists.get()) {
            mtMeetingCheckinpersonlistMapper.update(null,updateWrapper);
        } else {
            mtMeetingCheckinpersonlistMapper.insert(mtMeetingCheckinpersonlist);
        }

        return JsonVO.success("签到成功");
    }
}
