package com.zeroone.star.bizcenter.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.bizcenter.entity.CmsAppInfo;
import com.zeroone.star.project.vo.j5.bizcenter.publishProcessVO;

import java.util.List;

public interface CmsAppInfoService extends IService<CmsAppInfo>{

    /**
     * 查询公共流程
     * @return 公共流程
     */
    List<publishProcessVO> listPublishProcess();
}
