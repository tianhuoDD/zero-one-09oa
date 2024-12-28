package com.zeroone.star.project.vo.j4.form.data;




import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("表单详情显示对象")
public class FormInfoVO
{
    @ApiModelProperty(value = "表单id")
    private String xid;

//    @ApiModelProperty(value = "序号")
//    private String xsequence;

//    @ApiModelProperty(value = "分配因子")
//    private Integer xdistributeFactor;

//    @ApiModelProperty(value = "别名")
//    private String xalias;

//    @ApiModelProperty(value = "应用")
//    private String xapplication;

    @ApiModelProperty(value = "分类")
    private String xcategory;

//    @ApiModelProperty(value = "数据")
//    private String xdata;

    @ApiModelProperty(value = "描述")
    private String xdescription;

    @ApiModelProperty(value = "是否有移动端")
    private Boolean xhasMobile;

    @ApiModelProperty(value = "图标")
    private String xicon;

//    @ApiModelProperty(value = "最后更新人")
//    private String xlastUpdatePerson;

//    @ApiModelProperty(value = "负责人")
//    private String xperson;

//    @ApiModelProperty(value = "创建时间")
//    private LocalDateTime xcreateTime;

//    @ApiModelProperty(value = "最后更新时间")
//    private LocalDateTime xlastUpdateTime;

    @ApiModelProperty(value = "移动端数据")
    private String xmobileData;

    @ApiModelProperty(value = "名称")
    private String xname;

    @ApiModelProperty(value = "属性")
    private String xproperties;
}
