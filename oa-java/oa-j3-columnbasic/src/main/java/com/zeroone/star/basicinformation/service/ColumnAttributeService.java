package com.zeroone.star.basicinformation.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.basicinformation.entity.CmsForm;
import com.zeroone.star.project.j3.ColumnAttribute.dto.ColumnAttributeDTO;
import com.zeroone.star.project.j3.ColumnAttribute.vo.ColumnAttributeVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 阿伟
 * @since 2024-10-20
 */
public interface ColumnAttributeService extends IService<CmsForm> {

    // 查询栏目属性
    ColumnAttributeVO queryColumnAttribute(String xid);

    // 修改栏目属性
    boolean modifyCmsForm(ColumnAttributeDTO columnAttributeDTO);
}
