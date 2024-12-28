package com.zeroone.star.project.j3.appinfo.query;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("栏目查询对象")
public class AppQuery extends PageQuery {

    @ApiModelProperty(value = "栏目类型",example = "新闻")
    private String xappType;

    @ApiModelProperty(value = "栏目名称",example = "栏目1")
    private String xappName;

    @ApiModelProperty(value = "栏目别名",example = "别名1")
    private String xappAlias;

    @ApiModelProperty(value = "栏目描述",example = "这是一个很好的栏目")
    private String xdescription;


}
