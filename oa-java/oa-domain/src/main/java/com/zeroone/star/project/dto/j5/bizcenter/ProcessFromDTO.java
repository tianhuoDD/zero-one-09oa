package com.zeroone.star.project.dto.j5.bizcenter;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("流程表单 数据对象")
public class ProcessFromDTO {
    @ApiModelProperty("表单ID")
    private String id;

    @ApiModelProperty("表单别名")
    private String alias;

    @ApiModelProperty("表单名称")
    private String name;

    @ApiModelProperty("表单分类")
    private String category;

    @ApiModelProperty("所属应用")
    private String application;

    @ApiModelProperty("是否有移动端版本")
    private boolean hasMobile;

    @ApiModelProperty("表单数据")
    private String data;
}