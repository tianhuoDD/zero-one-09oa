package com.zeroone.star.bizcenter.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.*;
import com.zeroone.star.bizcenter.mapper.PpCTaskMapper;
import com.zeroone.star.bizcenter.service.*;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCTaskDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCTaskQuery;
import com.zeroone.star.project.utils.date.DateUtils;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.UUID;

/**
 * <p>
 *  服务实现类,查询待办记录
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
@Mapper(componentModel = "spring")
interface TaskTransfer{
    /**
     * @Description:  类型转换器，用于DO转DTO
     * @Param: PpCTask
     * @return:  PpCTaskDTO
     * @Author: hamhuo
     * @Date:
     */
    PpCTaskDTO task2taskDTO(PpCTask ppCTask);

}
@Service
public class PpCTaskServiceImpl extends ServiceImpl<PpCTaskMapper, PpCTask> implements IPpCTaskService {

    @Resource
    private TaskTransfer taskTransfer;

    @Autowired
    private IPpEManualService ppEManualService;

    @Autowired
    private IOrgIdentityService orgIdentityService;

    @Autowired
    private IOrgPersonService orgPersonService;

    @Autowired
    private IOrgUnitService orgUnitService;

    @Autowired
    private IPpEFromService  ppEFromService;

    @Autowired
    private PpCTaskMapper ppCTaskMapper;

    @Override
    public PageDTO<PpCTaskDTO> selectTaskByPerson (PpCTaskQuery query) {
        //构建分页对象,用于分页查询
        Page<PpCTask> page = new Page<>(query.getPageIndex(),query.getPageSize());

        //构建查询对象
        QueryWrapper<PpCTask> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xperson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //执行查询
        Page<PpCTask> result = baseMapper.selectPage(page,queryWrapper);
        return PageDTO.create(result, taskTransfer::task2taskDTO);
    }



    public PpCTask saveTask(UserDTO currentUser, String processId) {
        //1.插入pp_e_manual表
        String manualId = ppEManualService.savePpEManualWithProcessId(processId);

        //2.根据流程模板id查询流程模板
        PpEManual ppEManual = ppEManualService.getPpEManualById(manualId);

        //3.根据流程id查询 pp_e_from表
        PPEFrom ppeFrom = ppEFromService.getPpeFromById(processId);

        //4.根据用户id查询用户身份信息
        //TODO:UserDTO中的id为Long类型？
        OrgIdentity orgIdentity = orgIdentityService.getOrgIdentityByPersonId(currentUser.getId().toString());
        if (orgIdentity == null){
            throw new RuntimeException("orgIdentity 为空");
        }
        //5.根据用户id查询用户信息
        OrgPerson orgPerson = orgPersonService.getOrgIdentityById(currentUser.getId().toString());
        if (orgPerson == null){
            throw new RuntimeException("orgPerson 为空");
        }
        //6.根据xunit 查询单位信息
        OrgUnit orgUnit = orgUnitService.getOrgUnitById(orgIdentity.getXunit());
        if (orgUnit == null){
            throw new RuntimeException("orgUnit 为空");
        }

        //7.插入ppCTask表
        String uuid = UUID.randomUUID().toString();
        PpCTask ppCTask = PpCTask.builder()
                .xid(uuid)
                .xcreateTime(LocalDateTime.now())
                .xsequence(DateUtils.getDateToString() + uuid)
                .xupdateTime(LocalDateTime.now())
                .xdistributeFactor(null)
                .xactivity(ppEManual.getXid())
                .xactivityName(ppEManual.getXname())
                .xactivityType("manual")
                .xapplication(ppeFrom.getXapplication())
                .xactivityAlias(ppEManual.getXalias())
                .xactivityName(ppEManual.getXname())
                .xcreatorIdentity(orgIdentity.getXdistinguishedName())
                .xcreatorPerson(orgPerson.getXdistinguishedName())
                .xcreatorUnit(orgUnit.getXdistinguishedName())
                .xdistinguishedName(orgIdentity.getXdistinguishedName())
                .xexpired(false)
                .xfirst(true)
                .xidentity(orgIdentity.getXdistinguishedName())
                .xjob(uuid = UUID.randomUUID().toString())
                .xperson(orgPerson.getXdistinguishedName())
                .build();
        int affectRows = ppCTaskMapper.insert(ppCTask);
        if (affectRows <= 0){
            throw new RuntimeException("插入ppCTask表失败");
        }
        return ppCTask;
    }
}
