package com.zeroone.star.project.j3.datacofig;


import com.zeroone.star.project.j3.datacofig.dto.DataConfigDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：配置管理接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 落
 * @version 1.0.0
 */
public interface DataConfigApis {

    /**
     * 添加配置接口
     * @param dataConfigDTO 接收的配置数据
     * @return 配置的数据字典的id
     */
    JsonVO<String> addDataConfig(DataConfigDTO dataConfigDTO);


    /**
     * 修改配置接口
     * @param dataConfigDTO 接收的配置数据
     * @return 配置的数据字典的id
     */
    JsonVO<String> modifyDataConfig(DataConfigDTO dataConfigDTO);


    /**
     * 删除配置
     * @param id 配置的id
     * @return 删除的配置的id
     */
    JsonVO<String> removeDataConfig(String id);




}
