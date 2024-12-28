package com.zeroone.star.meetingmanagement.controller;

import com.zeroone.star.meetingmanagement.service.IMtAttachmentService;
import com.zeroone.star.project.dto.meetingmangement.AttachmentDTO;
import com.zeroone.star.project.j7.meetingmanagement.MtAttachmentApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("attachment")
@Api(tags = "会议附件管理")
public class MtAttachmentController implements MtAttachmentApis {

    @Resource
    private IMtAttachmentService mtAttachmentService;

    @Override
    @ApiOperation(value = "上传文件")
    @PostMapping("add")
    public JsonVO<String> addFile(@Validated AttachmentDTO attachmentDTO) {
        return mtAttachmentService.upload(attachmentDTO);
    }
}
