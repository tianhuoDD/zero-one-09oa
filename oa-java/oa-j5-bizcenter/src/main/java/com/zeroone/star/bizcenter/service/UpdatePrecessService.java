package com.zeroone.star.bizcenter.service;

import com.zeroone.star.project.dto.j5.bizcenter.PrecessingDTO;
import com.zeroone.star.project.dto.j5.bizcenter.ReplaceDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RerouteDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RollbackDTO;
import com.zeroone.star.project.vo.j5.bizcenter.RecordVO;
import com.zeroone.star.project.vo.j5.bizcenter.ReplaceVO;
import com.zeroone.star.project.vo.j5.bizcenter.RerouteVO;
import com.zeroone.star.project.vo.j5.bizcenter.RollbackVO;

import java.util.Map;

public interface UpdatePrecessService {
    /**
     * 修改工作业务数据
     * @param id
     * @param params
     */
    void updateWorkData(String id, Map<String, Object> params);

    /**
     * 插入放弃工作表
     * @param workId
     */
    String abandonedWork(String workId);

    /**
     * 关闭工作
     * @param id
     */
    Boolean closeWork(String id);

    /**
     * 重置处理人
     * @param id
     * @param replaceDTO
     * @return
     */
    ReplaceVO resetWorkPerson(String id, ReplaceDTO replaceDTO);

    /**
     * 继续流转
     * @param id
     * @param precessingDTO
     * @return
     */
    RecordVO updateProcessing(String id, PrecessingDTO precessingDTO);


    /**
     * 管理员调度
     * @param id
     * @param rerouteDTO
     * @return
     */
    RerouteVO reroute(String id, RerouteDTO rerouteDTO);

    /**
     * 管理员回溯
     * @param id
     * @param rollbackDTO
     * @return
     */
    RollbackVO rollBack(String id, RollbackDTO rollbackDTO);
}
