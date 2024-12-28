package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;
import java.util.ArrayList;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("开始活动数据对象")
public class BeginDTO {
    @ApiModelProperty(value = "开始活动的别名",example = "别名1")
    public String xalias;

    @ApiModelProperty(value = "主键ID",example = "08ed9ca1-c98e-4c11-bbdc-b68a346b649f")
    private String xid;

    @ApiModelProperty(value = "创建时间",example = "2024-10-24 21:21:33")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "更新时间",example = "2024-10-27 19:38:42")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "是否允许调度",example = "true")
    private Boolean xallowReroute;

    @ApiModelProperty(value = "是否允许调度到此活动",example = "true")
    private Boolean xallowRerouteTo;

    @ApiModelProperty(value = "描述信息",example = "")
    private String xdescription;

    @ApiModelProperty(value = "版本信息",example = "CAF11D4FA6200001C78217141FD1167E")
    private String xedition;

    @ApiModelProperty(value = "名字",example = "开始")
    private String xname;

    @ApiModelProperty(value = "位置信息",example = "260,40")
    private String xposition;

    @ApiModelProperty(value = "所属流程",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xprocess;

    @ApiModelProperty(value = "属性",example = "{}")
    private String xproperties;

    @ApiModelProperty(value = "路由",example = "6697d0cb-1709-448c-8324-ca2d16342fc6")
    private String xroute;

    @ApiModelProperty(value = "待阅人流程数据"/*,example = "[]"*/)
    private ArrayList<String> xreadDataPathList;

    @ApiModelProperty(value = "待阅人组织"/*,example = "[]"*/)
    private ArrayList<String> xreadGroupList;

    @ApiModelProperty(value = "待阅人身份",example = "[\"张三\",\"李四\"]")
    private ArrayList<String> xreadIdentityList;

    @ApiModelProperty(value = "待阅人信息"/*,example = "[]"*/)
    private ArrayList<String> xreadUnitList;

    @ApiModelProperty(value = "阅读人流程数据"/*,example = "[]"*/)
    private ArrayList<String> xreviewDataPathList;

    @ApiModelProperty(value = "阅读人组织"/*,example = "[]"*/)
    private ArrayList<String> xreviewGroupList;

    @ApiModelProperty(value = "阅读人身份"/*,example = "[]"*/)
    private ArrayList<String> xreviewIdentityList;

    @ApiModelProperty(value = "阅读人信息"/*,example = "[]"*/)
    private ArrayList<String> xreviewUnitList;



}
