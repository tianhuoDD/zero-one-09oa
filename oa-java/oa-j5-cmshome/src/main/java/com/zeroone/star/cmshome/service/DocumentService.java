package com.zeroone.star.cmshome.service;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetDocumentsListVO;

/**
 * @program: oa-java
 * @description: 文档服务接口
 * @author: Mr.Hang
 * @create: 2024-10-30 11:01
 **/
public interface DocumentService {
    //获取栏目列表
    JsonVO<PageDTO<GetDocumentsListVO>> getDocumentsList(String xcategoryName);
}
