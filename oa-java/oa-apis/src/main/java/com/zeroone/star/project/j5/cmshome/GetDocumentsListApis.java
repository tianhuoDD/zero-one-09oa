package com.zeroone.star.project.j5.cmshome;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetDocumentsListVO;

public interface GetDocumentsListApis {


    /**
     * 获取文档列表，支持条件查询和分页
     * @param appName 查询条件
     * @return 文档列表和分页信息
     */
    JsonVO<PageDTO<GetDocumentsListVO>> queryDocumentList(String  appName);

}
