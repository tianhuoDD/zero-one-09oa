package com.zeroone.star.project.dto.j4.procmanager.attachment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("附件文件信息操作对象")
public class AttachmentDTO {

    /**
     *附件唯一标识
     */

    @ApiModelProperty(value = "附件唯一标识",example = "e12312123")
    private String xid;

    /**
     *附件名
     */
    @ApiModelProperty(value = "附件名",example = "测试附件.jpg")
    private String xname;


    /**
     *附件别名
     */
    @ApiModelProperty(value = "附件别名",example = "测试附件别名")
    private String xalias;

}
