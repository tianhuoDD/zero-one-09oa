package com.zeroone.star.procmanager.service.impl;

import com.zeroone.star.procmanager.mapper.PpEProcessShowAndModifyMapper;
import com.zeroone.star.procmanager.service.IPpEprocessShowAndModifyService;
import com.zeroone.star.project.dto.j4.process.*;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class IPpEprocessShowAndModifyServiceImpl implements IPpEprocessShowAndModifyService {
    @Autowired
   PpEProcessShowAndModifyMapper ppEProcessShowAndModifyMapper;
    /**
     * 查询流程详情
     * 数据库表说明
     * pp_e_application - 应用程序模块
     * pp_e_begin - 开始模块
     * pp_cancel - 取消模块
     * pp_choice - 选择模块
     * pp_e_delay - 延迟模块
     * pp_e_embed - 嵌入模块
     * pp_e_end - 结束模块
     * pp_e_file - 文件模块
     * pp_e_form - 表单模块
     * pp_e_formfield - 表单字段模块
     * pp_e_invoke - 调用模块
     * pp_e_manual - 手动模块
     * pp_e_merge - 合并模块
     * pp_e_parallel - 并行模块
     * pp_e_process - 流程模块
     * pp_e_publish - 发布模块
     * pp_e_route - 路由模块
     * pp_e_script - 脚本模块
     * pp_e_service - 服务模块
     * pp_e_split - 拆分模块
     *
     * @param id 唯一编号
     * @return
     */

    @Override
    public List<PpEProcessDetailDto> ProcessShowDetail(String id) {
        //根据流程xid查询流程中涉及的路由，活动等
        //开始节点信息

        List<BeginDTO> ppEBeginDTOS = ppEProcessShowAndModifyMapper.selectstart(id);
        //路由节点信息

        List<RouteDTO> ppERouteDTOS = ppEProcessShowAndModifyMapper.selectroute(id);
        //手动模块节点信息

        List<ManualDTO> ppEManualDTOS = ppEProcessShowAndModifyMapper.selectmanual(id);
        //并行节点信息

        List<ParallelDTO> ppEParallelDTOS = ppEProcessShowAndModifyMapper.selectparallel(id);
        //合并节点信息

        List<MergeDTO> ppEMergeDTOS = ppEProcessShowAndModifyMapper.selectmerge(id);
        //结束节点信息

        List<EndDTO> ppEEndDTOS = ppEProcessShowAndModifyMapper.selectend(id);
        //封装整个流程所需要返回的信息
        List<PpEProcessDetailDto> list = new ArrayList<>();
                PpEProcessDetailDto  list1= new PpEProcessDetailDto();
                list1.setBeginDTO(ppEBeginDTOS);
                list1.setEndDTO(ppEEndDTOS);
                list1.setRouteDTO(ppERouteDTOS);
                list1.setManualDTO(ppEManualDTOS);
                list1.setParallelDTO(ppEParallelDTOS);
                list1.setMergeDTO(ppEMergeDTOS);
                list.add(list1);

        return list;
//        if (result != null){
//            return msPpEProcessMapper.ppEProcess2PpEprocessDTO(result);
//        }
//        return null;
//    }
    }

    @Override
    public void modifyProcess(ModifyProcessDTO ppEProcessDTO) {
        PpEProcessDTO eApplication = ppEProcessShowAndModifyMapper.selectById(ppEProcessDTO.getXid());

        ModifyProcessDTO process = new ModifyProcessDTO();
            BeanUtils.copyProperties(ppEProcessDTO,process);
            process.setXalias(ppEProcessDTO.getXalias());

        ppEProcessShowAndModifyMapper.update(process);
    }
}
