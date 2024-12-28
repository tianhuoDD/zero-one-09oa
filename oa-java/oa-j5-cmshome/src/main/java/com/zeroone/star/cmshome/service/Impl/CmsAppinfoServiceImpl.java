package com.zeroone.star.cmshome.service.impl;

import com.zeroone.star.cmshome.entity.CmsAppinfo;
import com.zeroone.star.cmshome.mapper.CmsAppinfoMapper;
import com.zeroone.star.cmshome.service.ICmsAppinfoService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 */
@Service
public class CmsAppinfoServiceImpl extends ServiceImpl<CmsAppinfoMapper, CmsAppinfo> implements ICmsAppinfoService {

    @Override
    public CmsAppinfo queryAppInfo(String xid) {
        CmsAppinfo cmsAppinfo = baseMapper.selectById(xid);
        return cmsAppinfo;
    }
}
