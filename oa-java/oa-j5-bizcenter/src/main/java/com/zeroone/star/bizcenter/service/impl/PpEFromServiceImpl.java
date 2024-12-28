package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.*;
import com.zeroone.star.bizcenter.mapper.PpEFromMapper;
import com.zeroone.star.bizcenter.service.*;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j5.bizcenter.ProcessFromDTO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFromVO;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


@Service
public class PpEFromServiceImpl extends ServiceImpl<PpEFromMapper, PPEFrom> implements IPpEFromService {
    @Autowired
    private PpEFromMapper ppEFromMapper;

    @Autowired
    private IPpEManualService ppEManualService;

    @Autowired
    private IPpCTaskService ppCTaskService;

    @Autowired
    private UserHolder userHolder;

    @Autowired
    private IQryItemService qryItemService;

    @Override
    @Transactional
    public ProcessFromVO getFromById(String id) {
        //1.插入pp_e_manual表
        String manualId = ppEManualService.savePpEManualWithProcessId(id);

        //2.根据流程模板id查询流程模板
        PpEManual ppEManual = ppEManualService.getPpEManualById(manualId);


        //3.获取当前用户信息
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(e+"-获取用户信息失败");
        }

        //4.插入pp_c_task表
        PpCTask ppCTask = ppCTaskService.saveTask(currentUser, id);

//    5.插入qry_item表
        //5.遍历ppCTask对象的属性，插入qry_item表 path1-属性名;xstringShoutValue-属性值
        qryItemService.saveItem(ppCTask);

        //6.根据流程id查询 pp_e_from表
        PPEFrom ppeFrom = ppEFromMapper.selectById(id);
        //将数据库表单转换为VO
        ProcessFromDTO processFromDTO = ProcessFromDTO.builder()
                .id(ppeFrom.getXid())
                .alias(ppeFrom.getXalias())
                .name(ppeFrom.getXname())
                .category(ppeFrom.getXcategory())
                .application(ppeFrom.getXapplication())
                .hasMobile(ppeFrom.getXhasMobile())
                .data(ppeFrom.getXdata())
                .build();

        //封装
        ProcessFromVO processFromVO = ProcessFromVO.builder().form(processFromDTO)
                .fastETag(id + System.currentTimeMillis()).build();
        return processFromVO;
    }

    /**
     * 根据id查询表单信息
     * @param id
     * @return
     */
    @Override
    public PPEFrom getPpeFromById(String id) {
        return ppEFromMapper.selectById(id);
    }
}
