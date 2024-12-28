package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpEManual;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
public interface IPpEManualService extends IService<PpEManual> {

    /**
     * 保存流程模板
     * @param processId 流程id
     */
    String savePpEManualWithProcessId(String processId);

    /**
     * 根据流程模板id查询流程模板
     * @param id 流程模板id
     * @return
     */
    PpEManual getPpEManualById(String id);

}
