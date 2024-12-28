package com.zeroone.star.project.j3.appinfo;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppTypeDTO;
import com.zeroone.star.project.j3.appinfo.query.AppQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 栏目信息接口定义
 */
public interface AppinfoApis {


    /**
     * 查询所有的栏目类型
     * @return 查询结果
     */
    JsonVO<List<AppTypeDTO>> queryAllType();

    /**
     * 查询具体的栏目
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<AppDTO>> queryApp(AppQuery condition);

}
