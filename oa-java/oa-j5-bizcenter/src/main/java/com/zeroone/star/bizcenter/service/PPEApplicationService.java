package com.zeroone.star.bizcenter.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.bizcenter.entity.PPEApplication;
import com.zeroone.star.project.vo.j5.bizcenter.ApplicationListVO;

import java.util.List;

public interface PPEApplicationService extends IService<PPEApplication> {
    /**
     * 查询应用列表
     * @return
     */
    public List<ApplicationListVO> listApplications();

    /**
     * 根据应用名称查询应用id
     * @param name 应用名称
     * @return 应用id
     */
    public String getApplicationIdByName(String name);

}
