package com.zeroone.star.project.j3.columnbasicinformation.vo;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：栏目基础信息返回对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chen
 * @since 2024-10-29
 */
@Data
@ApiModel("栏目基础信息传输对象")
public class BasicinformationVo {
    @ApiModelProperty(value = "编号")
    private String xid;
    @ApiModelProperty(value = "栏目名称",example = "测试栏目")
    private String xappName;
    @ApiModelProperty(value = "栏目别名",example = "测试")
    private String xappAlias;
    @ApiModelProperty(value = "栏目描述",example = "用于测试的栏目")
    private String xdescription;
    @ApiModelProperty(value = "栏目排序",example = "02")
    private String xappInfoSeq;
    @ApiModelProperty(value = "栏目类型",example = "测试")
    private String xappType;
    @ApiModelProperty("编辑表单")
    private List<String> writeForm;
    @ApiModelProperty("阅读表单")
    private List<String> readForm;
    @ApiModelProperty("栏目图标")
    private String xappIcon;
}
