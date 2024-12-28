package com.zeroone.star.procmanager.service;

import com.zeroone.star.project.dto.j4.process.ModifyProcessDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessDetailDto;

import java.util.List;

public interface IPpEprocessShowAndModifyService {
    /**
     * 查询流程详情
     * @param id
     * @return
     */
    List<PpEProcessDetailDto> ProcessShowDetail(String id);


     /*** 修改流程
     * @param ppEProcessDTO
     * @return
     */
    void modifyProcess(ModifyProcessDTO ppEProcessDTO);
}
