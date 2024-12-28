package com.zeroone.star.systemhome.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.vo.j1.system.home.ProcessInfoVo;
import com.zeroone.star.systemhome.entity.file.*;
import com.zeroone.star.systemhome.mapper.*;
import com.zeroone.star.systemhome.service.ProcessInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class ProcessInfoServiceImpl implements ProcessInfoService {
    @Autowired
    private PpCTaskMapper ppCTaskMapper;

    @Autowired
    private PpCTaskcompletedMapper ppCTaskcompletedMapper;

    @Autowired
    private PpCReadMapper ppCReadMapper;

    @Autowired
    private PpCReadcompletedMapper ppCReadcompletedMapper;

    @Autowired
    private PpCDraftMapper ppCDraftMapper;
    /**
     * 根据用户id获得流程信息
     * @param id 用户id
     * @return 封装为List,获取到的流程信息,获得待办，已办，待阅，已阅，草稿的数量
     */
    @Override
    public ProcessInfoVo getProcessInfo(String id) {
        ProcessInfoVo result = new ProcessInfoVo();

        // 待办
        // 在pp_c_task表中查询 xperson等于id的多行，并统计数量
        LambdaQueryWrapper<PpCTask> tlqw = new LambdaQueryWrapper<>();
        tlqw.eq(PpCTask::getXperson,id);
        Long taskL = ppCTaskMapper.selectCount(tlqw);
        result.setTask(taskL!= null ? taskL.intValue() : 0);

        // 已办
        // 在pp_c_taskcompleted表中查询 xperson等于id的多行，并统计数量
        LambdaQueryWrapper<PpCTaskcompleted> tclqw = new LambdaQueryWrapper<>();
        tclqw.eq(PpCTaskcompleted::getXperson,id);
        Long taskCL = ppCTaskcompletedMapper.selectCount(tclqw);
        result.setTaskCompleted(taskCL!= null ? taskCL.intValue() : 0);

        //待阅
        //从pp_c_read表中查询 xperson为Stringid的 , xcompleted = 0 ,xviewTime IS NULL的
        //并统计
        LambdaQueryWrapper<PpCRead> rlqw = new LambdaQueryWrapper<>();
        rlqw.eq(PpCRead::getXperson,id);
        rlqw.eq(PpCRead::getXcompleted,0);
        rlqw.eq(PpCRead::getXviewTime,null);
        Long readL = ppCReadMapper.selectCount(rlqw);
        result.setRead(readL!= null ? readL.intValue() : 0);

        //已阅
        // 在pp_c_readcompleted表中查询 xperson等于id的多行，并统计数量
        LambdaQueryWrapper<PpCReadcompleted> rclqw = new LambdaQueryWrapper<>();
        rclqw.eq(PpCReadcompleted::getXperson,id);
        Long readCL = ppCReadcompletedMapper.selectCount(rclqw);
        result.setReadCompleted(readCL!= null ? readCL.intValue() : 0);

        //草稿
        // 在pp_c_draft表中查询 xperson等于id的多行，并统计数量
        LambdaQueryWrapper<PpCDraft> dlqw = new LambdaQueryWrapper<>();
        dlqw.eq(PpCDraft::getXperson,id);
        Long draftL = ppCDraftMapper.selectCount(dlqw);
        result.setDraft(draftL!= null ? draftL.intValue() : 0);

        return result;
    }
}
