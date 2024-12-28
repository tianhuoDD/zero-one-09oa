package com.zeroone.star.procmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessPageDTO;
import com.zeroone.star.project.query.j4.pocess.PpEProcessQuery;
import com.zeroone.star.procmanager.entity.PpEProcess;

import java.util.List;
import java.util.Map;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author qy
 * @since 2024-10-21
 */
public interface IPpEProcessService extends IService<PpEProcess> {
    /**
     * 查询返回所有类型
     *
     * @return 查询到的类型
     */
    List<Map<String, Object>> countCategory();
    /**
     * 分页查询所有数据
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<PpEProcessPageDTO> listAll(PpEProcessQuery query);

}
