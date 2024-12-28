package com.zeroone.star.project.j4.process;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessPageDTO;
import com.zeroone.star.project.query.j4.pocess.PpEProcessQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;
import java.util.Map;

public interface ProcessQueryApis {
    /**
     * 通过类型列出流程
     * @return 查询返回类型
     */
    JsonVO<List<Map<String,Object>>> countByCategory();

    /**
     * 流程分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<PpEProcessPageDTO>> queryAll(PpEProcessQuery condition);


}
