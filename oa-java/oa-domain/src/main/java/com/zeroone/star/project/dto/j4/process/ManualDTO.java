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
@ApiModel("人工活动数据对象")
public class ManualDTO {
    @ApiModelProperty(value = "主键ID",example = "cc88613a-637d-41fb-ace6-8f4ba4a0063b")
    private String xid;

    @ApiModelProperty(value = "创建时间",example = "2024-10-24 21:21:33")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "更新时间",example = "2024-10-27 19:38:42")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "别名",example = "别名1")
    private String xalias;

    @ApiModelProperty(value = "允许增加拆分分支",example = "false")
    private Boolean xallowAddSplit;

    @ApiModelProperty(value = "允许删除文件",example = "false")
    private Boolean xallowDeleteWork;

    @ApiModelProperty(value = "允许终止文件",example = "false")
    private Boolean xallowPause;

    @ApiModelProperty(value = "允许与否",example = "false")
    private Boolean xallowPress;

    @ApiModelProperty(value = "允许快速处理",example = "false")
    private Boolean xallowRapid;

    @ApiModelProperty(value = "是否允许调度",example = "false")
    private Boolean xallowReroute;

    @ApiModelProperty(value = "是否允许调度到此活动",example = "false")
    private Boolean xallowRerouteTo;

    @ApiModelProperty(value = "是否允许重置",example = "false")
    private Boolean xallowReset;

    @ApiModelProperty(value = "是否允许撤回",example = "false")
    private Boolean xallowRetract;

    @ApiModelProperty(value = "允许退回",example = "false")
    private Boolean xallowRollback;

    @ApiModelProperty(value = "描述信息",example = "")
    private String xdescription;

    @ApiModelProperty(value = "版本信息",example = "CAF272ECC55000017BFBE6801DBB7650")
    private String xedition;

    @ApiModelProperty(value = "延伸信息",example = "")
    private String xextension;

    @ApiModelProperty(value = "表单信息",example = "")
    private String xform;

    @ApiModelProperty(value = "信息",example = "false")
    private Boolean xmanualMergeSameJobActivity;

    @ApiModelProperty(value = "处理方式",example = "single")
    private String xmanualMode;

    @ApiModelProperty(value = "信息",example = "false")
    private Boolean xmanualUncompletedTaskToRead;

    @ApiModelProperty(value = "名字",example = "取消")
    private String xname;

    @ApiModelProperty(value = "信息",example = "")
    private String xopinionGroup;

    @ApiModelProperty(value = "位置信息",example = "680,160")
    private String xposition;

    @ApiModelProperty(value = "流程信息",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xprocess;

    @ApiModelProperty(value = "属性",example = "")
    private String xproperties;

    @ApiModelProperty(value = "待阅人职务",example = "")
    private String xreadDuty;

    @ApiModelProperty(value = "阅读人职务",example = "")
    private String xreviewDuty;

    @ApiModelProperty(value = "处理人职务",example = "")
    private String xtaskDuty;

    @ApiModelProperty(value = "处理预期天数",example = "10")
    private Integer xtaskExpireDay;

    @ApiModelProperty(value = "处理预期时长",example = "10")
    private Integer xtaskExpireHour;

    @ApiModelProperty(value = "预期处理类型",example = "")
    private String xtaskExpireType;

    @ApiModelProperty(value = "信息",example = "true")
    private Boolean xtaskExpireWorkTime;

    @ApiModelProperty(value = "流程数据",example = "")
    private ArrayList<String> xreadDataPathList;

    @ApiModelProperty(value = "待阅人组织",example = "")
    private ArrayList<String> xreadGroupList;

    @ApiModelProperty(value = "待阅人身份",example = "")
    private ArrayList<String> xreadIdentityList;

    @ApiModelProperty(value = "待阅人信息",example = "")
    private ArrayList<String> xreadUnitList;

    @ApiModelProperty(value = "流程数据",example = "")
    private ArrayList<String> xreviewDataPathList;

    @ApiModelProperty(value = "阅读人组织",example = "")
    private ArrayList<String> xreviewGroupList;

    @ApiModelProperty(value = "阅读人身份",example = "")
    private ArrayList<String> xreviewIdentityList;

    @ApiModelProperty(value = "阅读人信息",example = "")
    private ArrayList<String> xreviewUnitList;

    @ApiModelProperty(value = "路由列表",example = "")
    private ArrayList<String> xrouteList;

    @ApiModelProperty(value = "流程数据",example = "")
    private ArrayList<String> xtaskDataPathList;

    @ApiModelProperty(value = "处理人组织",example = "")
    private ArrayList<String>  xtaskGroupList;

    @ApiModelProperty(value = "处理人身份",example = "")
    private ArrayList<String>  xtaskIdentityList;

    @ApiModelProperty(value = "处理人信息",example = "")
    private ArrayList<String>  xtaskUnitList;

}
