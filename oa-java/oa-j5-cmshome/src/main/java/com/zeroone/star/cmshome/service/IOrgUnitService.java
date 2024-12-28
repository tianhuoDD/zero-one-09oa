package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.OrgUnit;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-28
 */
public interface IOrgUnitService extends IService<OrgUnit> {

    OrgUnit queryById(String xid);
}
