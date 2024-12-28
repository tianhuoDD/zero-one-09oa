package com.zeroone.star.cmshome.controller;

import com.zeroone.star.cmshome.service.DocumentService;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetDocumentsListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * @program: oa-java
 * @description: 获取文档列表接口
 */
@RestController
@RequestMapping("cmshome/api/documents")
@Api(tags = "获取文档列表")
@Slf4j
@Validated
public class GetDocumentsListController {

    private final DocumentService documentService; // 引入Service

    @Autowired
    public GetDocumentsListController(@SuppressWarnings("SpringJavaInjectionPointsAutowiringInspection") DocumentService documentService) { // 注入Service
        this.documentService = documentService;
    }

    /**
     * 获取文档列表，按固定分页参数返回
     *
     * @param xcategoryName 文档类型（如“草稿”、“领用记录”等）
     * @return 分页后的文档列表信息
     */
    @GetMapping("/list")
    @ApiOperation(value = "获取文档列表", notes = "根据文档类型名称（如“草稿”或“领用记录”）获取分页后的文档列表")
    public JsonVO<PageDTO<GetDocumentsListVO>> getDocumentsList(
            @RequestParam(value = "xcategoryName", required = false) String xcategoryName) {

        // 调用服务接口获取分页数据，只传递xcategoryName
        return documentService.getDocumentsList(xcategoryName);
    }
}
