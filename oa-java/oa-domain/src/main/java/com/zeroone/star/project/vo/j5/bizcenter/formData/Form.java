package com.zeroone.star.project.vo.j5.bizcenter.formData;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

@Data
@ApiModel("流程表单格式")

public class Form {

    @ApiModelProperty(value = "表单id",example = "81c88d0e-828d-427c-8ab5-8606e4a837a8")
    private String xid;

    @ApiModelProperty(value = "表单名",example = "出差申请表")
    private String xname;

    @ApiModelProperty(value = "表单名的别名",example = "出差申请表")
    private String xalias;

    @ApiModelProperty(value = "表单分类",example = "出差")
    private String xcategory;

    @ApiModelProperty(value = "表单模板类id",example = "1d5f9c01-11e6-4e68-bb79-72d12f27ebee")
    private String xapplication;

    @ApiModelProperty(value = "是否可移动",example = "true")
    private Boolean xhasMobile;

    @ApiModelProperty(value = "表单格式",example = "这个一个json数据")
    private String xdata;
}
