package com.zeroone.star.project.query.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("获取表单数据")
public class ProcessFormDataQuery {

    @ApiModelProperty(value = "流程表单id",example = "707ae1d2-54ef-4413-a6ea-8697f9b129d1")
    private String id;

    @ApiModelProperty(value = "填写表单的人的id",example = "707ae1d2-54ef-4413-a6ea-8697f9b129d1")
    private String creatorPerson;
}
