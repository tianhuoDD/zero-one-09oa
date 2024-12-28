package com.zeroone.star.basicinformation.service;

import com.zeroone.star.basicinformation.entity.CmsAppinfoConfig;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoConfigDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author Kokoro
 * @since 2024-10-20
 */
public interface ICmsAppinfoConfigService extends IService<CmsAppinfoConfig> {

    //添加栏目配置
    Integer addColumnConfig(AppinfoConfigDTO appinfoConfigDTO);

    //删除栏目配置
    Integer deleteColumnConfig(String xid);
}
