package com.zeroone.star.bizcenter.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.bizcenter.entity.zyPPEProcess;

import java.util.List;

public interface zyPPEProcessService extends IService<zyPPEProcess> {

    /**
     *  根据应用id 查找流程列表
     * @param appId 应用id
     * @return 流程列表
     */
    public List<zyPPEProcess> listProcessListByAppId(String appId);
}
