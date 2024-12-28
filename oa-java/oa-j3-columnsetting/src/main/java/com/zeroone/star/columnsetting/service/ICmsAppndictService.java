package com.zeroone.star.columnsetting.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.columnsetting.entity.CmsAppndict;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigDetailVO;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author ikun
 * @since 2024-10-20
 */
public interface ICmsAppndictService extends IService<CmsAppndict> {

    List<dataConfigVO> getDataConfigList();

    dataConfigDetailVO getDataConfig(String xid);
}
