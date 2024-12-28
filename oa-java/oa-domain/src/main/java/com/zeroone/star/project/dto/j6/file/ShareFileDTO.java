package com.zeroone.star.project.dto.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：共享文件传输数据对象
 * </p>
 * @author qi
 * @version 1.0.0
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("共享文件传输数据对象")
public class ShareFileDTO {

    @ApiModelProperty(value = "文件ID", example = "456")
    private Long fileId;

    @ApiModelProperty(value = "文件名称", example = "项目文档")
    private String fileName;

    @ApiModelProperty(value = "文件类型", example = "pdf")
    private String fileType;

    @ApiModelProperty(value = "文件大小（字节）", example = "102400")
    private Long fileSize;

    @ApiModelProperty(value = "文件URL", example = "http://example.com/files/456.pdf")
    private String fileUrl;

    @ApiModelProperty(value = "上传时间", example = "2023-10-01T12:34:56")
    private String uploadTime;

    @ApiModelProperty(value = "共享用户ID", example = "user123")
    private String sharedUserId;

    @ApiModelProperty(value = "共享时间", example = "2023-10-01T10:00:00")
    private String sharedTime;

}
