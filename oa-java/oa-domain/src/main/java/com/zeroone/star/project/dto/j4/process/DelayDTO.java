package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.ArrayList;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("定时活动数据对象")
public class DelayDTO {
    @ApiModelProperty(value = "主键ID",example = "c967390c-3687-40e2-8abf-2a5caf48cee6")
    private String xid;

    @ApiModelProperty(value = "定时活动的创建时间",example = "2024-10-24 21:21:33")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "定时活动的更新时间",example = "2024-10-27 19:38:42")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "定时活动的别名",example = "别名1")
    private String xalias;

    @ApiModelProperty(value = "是否允许调度，false表示不允许，true表示允许",example = "false")
    private Boolean xallowReroute;

    @ApiModelProperty(value = "是否允许调度到此活动，false表示不允许，true表示允许",example = "false")
    private Boolean xallowRerouteTo;

    @ApiModelProperty(value = "指定数据路径",example = "")
    private String xdelayDataPath;

    @ApiModelProperty(value = "指定分钟",example = "")
    private Integer xdelayMinute;

    @ApiModelProperty(value = "定时方式",example = "minute")
    private String xdelayType;

    @ApiModelProperty(value = "定时活动的描述",example = "")
    private String xdescription;

    @ApiModelProperty(value = "定时活动的版本",example = "CAF274795AC00001D81F16531DB017E0")
    private String xedition;

    @ApiModelProperty(value = "定时活动的延伸",example = "")
    private String xextension;

    @ApiModelProperty(value = "定时活动的表单",example = "")
    private String xform;

    @ApiModelProperty(value = "定时活动的名字",example = "定时")
    private String xname;

    @ApiModelProperty(value = "定时活动的位置",example = "500,540")
    private String xposition;

    @ApiModelProperty(value = "定时活动所属的流程",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xprocess;

    @ApiModelProperty(value = "定时活动的属性",example = "{}")
    private String xproperties;

    @ApiModelProperty(value = "定时活动的待阅人职务",example = "局长")
    private String xreadDuty;

    @ApiModelProperty(value = "定时活动的阅读人职务",example = "厂长")
    private String xreviewDuty;

    @ApiModelProperty(value = "路由",example = "3e92257a-3637-4938-a82c-1dce04cf8c85")
    private String xroute;

    @ApiModelProperty(value = "是否仅计算工作时间",example = "true")
    private boolean xworkMinute;

    @ApiModelProperty(value = "定时活动的待阅人流程数据",example = "[]")
    private ArrayList<String> xreadDataPathList;

    @ApiModelProperty(value = "定时活动的待阅人组织",example = "[\"company1\"]")
    private ArrayList<String> xreadGroupList;

    @ApiModelProperty(value = "定时活动的待阅人身份",example = "[\"张三\"]")
    private ArrayList<String> xreadIdentityList;

    @ApiModelProperty(value = "定时活动的待阅人数据",example = "[]")
    private ArrayList<String> xreadUnitList;

    @ApiModelProperty(value = "定时活动的阅读人流程数据",example = "[]")
    private ArrayList<String> xreviewDataPathList;

    @ApiModelProperty(value = "定时活动的阅读人组织",example = "[\"conmany1\"]")
    private ArrayList<String> xreviewGroupList;

    @ApiModelProperty(value = "定时活动的阅读人身份",example = "[\"李四\"]")
    private ArrayList<String> xreviewIdentityList;

    @ApiModelProperty(value = "定时活动的阅读人数据",example = "[]")
    private ArrayList<String> xreviewUnitList;
}
