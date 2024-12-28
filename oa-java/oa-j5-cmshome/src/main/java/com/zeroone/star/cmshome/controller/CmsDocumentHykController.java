package com.zeroone.star.cmshome.controller;

import com.zeroone.star.cmshome.service.CmsDocumentHykService;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnMessagesVO;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/cmshome")
@Api(tags = "获取栏目信息")
@Slf4j
@Validated
public class CmsDocumentHykController {

    @Autowired
    private CmsDocumentHykService columnMessagesService;

    @GetMapping("/query-column-messages/{xid}")
    @ApiOperation("获取栏目信息")
    public JsonVO<List<GetColumnMessagesVO>> queryColumnMessages(@PathVariable String xid) {
        log.info("进入 queryColumnMessages 方法, xid = {}", xid);

        List<GetColumnMessagesVO> columnMessages = columnMessagesService.getColumnMessages(xid).getData();

        if (columnMessages == null || columnMessages.isEmpty()) {
            log.warn("未找到对应的栏目信息, xid = {}", xid);
            return new JsonVO<>(200, "未找到对应的栏目信息", null);
        }

        return new JsonVO<>(200, "成功", columnMessages);
    }
}
