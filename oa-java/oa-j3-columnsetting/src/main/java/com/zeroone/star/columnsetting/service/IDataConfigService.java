package com.zeroone.star.columnsetting.service;

import com.zeroone.star.project.j3.datacofig.dto.DataConfigDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author luo
 * @since 2024-10-20
 */
public interface IDataConfigService {

    /**
     * 删除配置
     *
     * @param id 数据配置的id
     * @return 删除的数据配置的id
     */
    String removeById(String id);

    /**
     * 添加数据配置接口
     *
     * @param dataConfigDTO 接收的数据配置参数
     * @return 数据配置的id
     */
    String saveDataConfig(DataConfigDTO dataConfigDTO);


    /**
     * 修改配置接口
     *
     * @param dataConfigDTO 接收的数据配置参数
     * @return 数据配置的id
     */
    String update(DataConfigDTO dataConfigDTO);
}
