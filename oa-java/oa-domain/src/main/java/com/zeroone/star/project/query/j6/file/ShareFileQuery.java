package com.zeroone.star.project.query.j6.file;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

/**
 * <p>
 * 描述：指定共享用户共享文件分页查询对象
 * </p>
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("指定共享用户共享文件分页查询对象")
public class ShareFileQuery extends PageQuery {
    @NotNull(message = "用户ID不能为空")
    @ApiModelProperty(value = "用户ID", example = "1001", required = true)
    private Long userId;

    @ApiModelProperty(value = "文件类型", example = "pdf", required = false)
    private String fileType;

    @ApiModelProperty(value = "排序字段", example = "sharedTime", required = false)
    private String sortField;

    @ApiModelProperty(value = "排序方式（asc/desc）", example = "desc", required = false)
    private String sortOrder;
}
