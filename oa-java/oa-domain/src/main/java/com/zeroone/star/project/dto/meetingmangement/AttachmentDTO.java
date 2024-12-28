package com.zeroone.star.project.dto.meetingmangement;

import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.Min;

@Data
public class AttachmentDTO {
    @Min(value = 1, message = "会议ID不能为空")
    private int meetingXid;

    private MultipartFile file;
}
