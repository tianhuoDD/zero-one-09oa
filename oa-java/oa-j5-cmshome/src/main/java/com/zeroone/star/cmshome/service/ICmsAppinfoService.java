package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.CmsAppinfo;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 */
public interface ICmsAppinfoService extends IService<CmsAppinfo> {

    /*
    * 根据appid查询app信息
    */
    CmsAppinfo queryAppInfo(String xid);

}
