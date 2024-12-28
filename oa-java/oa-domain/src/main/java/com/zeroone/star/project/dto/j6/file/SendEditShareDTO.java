package com.zeroone.star.project.dto.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：发送可编辑共享文件，指定用户可以编辑文件
 * </p>
 * @author : nkjjkl
 * @version : V1.0.0
 */
@Data
@ApiModel("可编辑共享文件对象")
public class SendEditShareDTO {
    @ApiModelProperty(value = "文件表文件ID", example = "066cf4f2-bdee-4c2a-b354-798e9f6a393a")
    private String xid;
    @ApiModelProperty(value = "可编辑共享表文件ID", example = "066cf4f2-bdee-4c2a-b354-798e9f6a393a")
    private String ATTACHMENT_XID;
    @ApiModelProperty(value = "可编辑者ID列表", example = "[066cf4f2-bdee-4c2a-b354-798e9f6a393a,41dee027-e917-44b1-a337-2cf7a546c61a]")
    private List<String> xeditorList;
}
