package com.zeroone.star.bizcenter.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.bizcenter.entity.CmsCategoryInfo;

import java.util.List;

public interface CmsCategoryInfoService extends IService<CmsCategoryInfo> {

    /**
     * 根据应用id 查找 流程列表
     * @param appId 应用id
     * @return 流程列表
     */
    List<CmsCategoryInfo> listProcessListByAppId(String appId);
}
