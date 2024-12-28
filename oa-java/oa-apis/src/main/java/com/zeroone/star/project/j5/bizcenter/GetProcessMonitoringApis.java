package com.zeroone.star.project.j5.bizcenter;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ComplexVO;

/**
 * 流程api
 */
public interface GetProcessMonitoringApis {


    /**
     * 获取流程内容，附带所有的活动节点信息
     * @param flag 流程监控
     * @return
     */
    JsonVO<ComplexVO> getComplex(String flag);

}
