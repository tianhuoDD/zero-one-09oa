package com.zeroone.star.bizcenter.service;

import com.zeroone.star.project.vo.j5.bizcenter.ComplexVO;

public interface GetProcessMonitoringService {


    /**
     * 获取流程监控
     * @param flag
     * @return
     */

    ComplexVO getComplex(String flag);
}
