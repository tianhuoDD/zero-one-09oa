package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.CmsCategoryinfo;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-25
 */
public interface ICmsCategoryinfoService extends IService<CmsCategoryinfo> {

    /**
     * 根据id查询分类信息
     * @param xid 分类id
     * @return 分类信息
     */
    CmsCategoryinfo queryCategory(String xid);
}
