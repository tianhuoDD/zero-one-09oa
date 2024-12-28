package com.zeroone.star.procmanager.controller;

import com.zeroone.star.procmanager.service.AttachmentQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.j4.procmanager.attachment.AttachmentQueryApis;
import com.zeroone.star.project.query.j4.procmanager.attachment.AttachmentQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import javax.validation.constraints.Min;

@RestController
@RequestMapping("attachment")
@Api(tags = "附件查询相关接口")
@Validated
public class AttachmentQueryController implements AttachmentQueryApis {

    @Resource
    AttachmentQueryService attachmentQueryService;

    /**
     * 获取附件列表
     * @param condition 查询条件
     * @return
     */
    @GetMapping("query-all")
    @ApiOperation(value = "获取附件列表")
    @Override
    public JsonVO<PageDTO<AttachmentDTO>> queryAll(AttachmentQuery condition) {
        return JsonVO.success(attachmentQueryService.queryAll(condition));
    }


    /**
     * 获取附件详情
     * @param id 附件ID
     * @return
     */
    @Override
    public JsonVO<AttachmentDTO> queryById(int id) {
        return JsonVO.success(attachmentQueryService.getById(id));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "获取附件详情")
    public JsonVO<AttachmentDTO> queryByIdV(@Validated
                                                @RequestParam
                                                @Min(value = 1, message = "id最小值为1") int id) {
        return queryById(id);
    }

}
