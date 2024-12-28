package com.zeroone.star.project.vo.j4.procmanager.attachment;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 附件视图对象。
 */
@Data
@ApiModel("附件视图对象")
public class AttachmentVO {
    @ApiModelProperty(value = "附件名称", example = "image.png")
    private String xname;

    @ApiModelProperty(value = "附件别名", example = "图片")
    private String xalias;

    @ApiModelProperty(value = "附件文件大小",example = "723891")
    private String xlength;

    @ApiModelProperty(value = "附件URL", example = "http://example.com/file.png")
    private String xurl;
}
