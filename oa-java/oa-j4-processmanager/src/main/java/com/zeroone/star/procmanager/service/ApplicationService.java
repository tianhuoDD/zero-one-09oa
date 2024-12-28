package com.zeroone.star.procmanager.service;



import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.procmanager.entity.PpEApplication;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.procmanager.application.manage.ApplicationQuery;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.CategoryVo;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author nefertari
 * @since 2024-10-20
 */
public interface ApplicationService extends IService<PpEApplication> {

    /**
     * 查询所有应用分类和对应的应用的个数
     * @return
     */
    List<CategoryVo> listAndCountApplicationCategory();

    /**
     * 查询所有应用
     * @return
     */
    PageDTO<ApplicationVo> listApplication(ApplicationQuery applicationQuery);

    /**
     * 查询指定应用
     * @param id
     * @return
     */
    ApplicationPropertiesVo getApplication(String id);
}
