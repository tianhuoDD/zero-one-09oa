package com.zeroone.star.cmshome.service.impl;



import com.zeroone.star.cmshome.mapper.CmsDocumentHykMapper;
import com.zeroone.star.cmshome.service.DocumentService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetDocumentsListVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DocumentServiceImpl implements DocumentService {

    @Autowired
    private CmsDocumentHykMapper cmsDocumentHykMapper;

    //获取文档列表
    // 定义默认的分页参数
    private static final Long DEFAULT_PAGE_INDEX = 1L; // 默认页码
    private static final Long DEFAULT_PAGE_SIZE = 10L; // 默认每页显示记录数

    @Override
    public JsonVO<PageDTO<GetDocumentsListVO>> getDocumentsList(String xcategoryName) {
        // 使用默认的分页参数
        Long pageIndex = DEFAULT_PAGE_INDEX; // 从1开始
        Long pageSize = DEFAULT_PAGE_SIZE; // 每页显示的记录数
        Long offset = (pageIndex - 1) * pageSize; // 计算偏移量

        // 获取总记录数以进行分页
        Long totalRecords = cmsDocumentHykMapper.countDocuments(xcategoryName);

        // 计算总页数
        Long pages = (totalRecords + pageSize - 1) / pageSize;

        // 查询分页列表，注意这里需要传递 offset 参数
        List<GetDocumentsListVO> documentList = cmsDocumentHykMapper.getDocumentsWithDetails(xcategoryName, pageSize, offset);

        // 将结果打包成 PageDTO
        PageDTO<GetDocumentsListVO> pageDTO = new PageDTO<>(pageIndex, pageSize, totalRecords, pages, documentList);

        return new JsonVO<>(200, "查询成功", pageDTO);
    }


}
