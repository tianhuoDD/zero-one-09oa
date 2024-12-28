package com.zeroone.star.project.query.j4.procmanager.attachment;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.Min;

/**
 * 附件查询参数类。
 */
@Getter
@Setter
@ToString
public class AttachmentQuery extends PageQuery {
    @ApiModelProperty(value = "附件名称", example = "image.png")
    private String name;

    @ApiModelProperty(value = "流程实例ID", example = "12345")
    private String processInstanceId;

    @Min(value = 1, message = "页码最小值为1")
    @ApiModelProperty(value = "查询页码", example = "1")
    private long pageIndex;

    @Min(value = 1, message = "条数最小值为1")
    @ApiModelProperty(value = "查询条数", example = "10")
    private long pageSize;
}
