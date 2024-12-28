package com.zeroone.star.project.vo.j4.procmanager.AddApplicationVo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("新增数据配置显示对象")
public class AddDataConfigVo {
    @ApiModelProperty(value = "名称", example = "请假管理")
    private String name;

    @ApiModelProperty(value = "别名", example = "请假")
    private String alias;

    @ApiModelProperty(value = "描述", example = "管理请假手续的流程")
    private String description;

    @ApiModelProperty(value = "分类", example = "日常")
    private String category;

    @ApiModelProperty(value = "头像地址", example = "icon_url")
    private String icon;

    @ApiModelProperty(value = "表单名称列表")
    private List<String> formList;

    @ApiModelProperty(value = "流程名称列表")
    private List<String> processList;
}

