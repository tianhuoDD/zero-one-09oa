package com.zeroone.star.project.vo.j5.cmshome.form;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("表单数据")
public class DocumentFormDataVO {

    @ApiModelProperty("唯一标识")
    private String xid;

    @ApiModelProperty("消息别名")
    private String xalias;

    @ApiModelProperty("消息名称")
    private String xname;

    @ApiModelProperty("消息id")
    private String xappId;

    @ApiModelProperty("消息表单模板")
    private DocumentFormVO data;
}
