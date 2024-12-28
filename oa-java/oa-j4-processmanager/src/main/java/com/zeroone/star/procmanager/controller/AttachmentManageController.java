package com.zeroone.star.procmanager.controller;

import com.zeroone.star.procmanager.service.AttachmentManagerService;
import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.j4.procmanager.attachment.AttachmentManageApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

@RestController
@RequestMapping("/attachment")
@RequiredArgsConstructor
@Api(tags = "附件管理相关接口")
public class AttachmentManageController implements AttachmentManageApis {

    private final AttachmentManagerService attachmentManagerService;

    @Override
    @PostMapping("/add-attachment")
    @ApiOperation("新增附件(若attachmentId不为空则是在附件详情页面重新上传附件，否则新增一个完全不存在的附件)")
    public JsonVO<String> addAttachment(
                                        @RequestHeader("Application_ID") String applicationId,
                                        MultipartFile file,
                                        String attachmentId) {
        return attachmentManagerService.saveAttachment(applicationId,file,attachmentId);
    }

    @Override
    @PutMapping("/modify-attachment")
    @ApiOperation("修改附件")
    public JsonVO<String> modifyAttachment(AttachmentDTO attachmentDTO) {
        return attachmentManagerService.updateAttachment(attachmentDTO);
    }

    @Override
    @DeleteMapping("/remove-attachment")
    @ApiOperation("删除附件 (参数xids可传入多个xid 以','分割)")
    public JsonVO<String> removeAttachment(String xids) {
        return attachmentManagerService.removeAttachment(xids);
    }
}
