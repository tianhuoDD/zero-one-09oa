package com.zeroone.star.project.j4.application;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.procmanager.application.manage.ApplicationQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.CategoryVo;

import java.util.List;
/**
 * <p>
 * 描述：应用设置的相关接口声明
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
public interface ApplicationManageApis {
    /**
     *  查询所有应用类型
     * @return
     */
    JsonVO<List<CategoryVo>> queryCategoryAll();

    /**
     *  分页 + 条件 查询所有应用
     * @param query
     * @return
     */
    JsonVO<PageDTO<ApplicationVo>> queryApplicationAll(ApplicationQuery query);

    /**
     *  根据id查询应用属性
     * @param id
     * @return
     */
    JsonVO<ApplicationPropertiesVo> queryApplicationById(String id);
}
