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
@ApiModel("流程调用数据对象")
public class EmbedDTO {
    @ApiModelProperty(value = "主键ID",example = "cc88613a-637d-41fb-ace6-8f4ba4a0063r")
    private String xid;

    @ApiModelProperty(value = "创建时间",example = "2024-10-24 21:21:33")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "更新时间",example = "2024-10-27 19:38:42")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "别名",example = "别名1")
    private String xalias;

    @ApiModelProperty(value = "是否允许调度",example = "1")
    private Boolean xallowReroute;

    @ApiModelProperty(value = "是否允许调度到此活动",example = "1")
    private Boolean xallowRerouteTo;

    @ApiModelProperty(value = "描述信息",example = "")
    private String xdescription;

    @ApiModelProperty(value = "版本信息",example = "CAF272ECC55000017BFBE6801DBB7650")
    private String xedition;

    @ApiModelProperty(value = "启动者",example = "lastIdentity")
    private String xembedCreatorType;

    @ApiModelProperty(value = "延伸信息",example = "")
    private String xextension;

    @ApiModelProperty(value = "表单信息",example = "")
    private String xform;

    @ApiModelProperty(value = "是否拷贝附件",example = "false")
    private Boolean xinheritAttachment;

    @ApiModelProperty(value = "是否拷贝数据",example = "true")
    private Boolean xinheritData;

    @ApiModelProperty(value = "名字",example = "取消")
    private String xname;

    @ApiModelProperty(value = "位置信息",example = "680,160")
    private String xposition;

    @ApiModelProperty(value = "流程信息",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xprocess;

    @ApiModelProperty(value = "属性",example = "{}")
    private String xproperties;

    @ApiModelProperty(value = "待阅人职务",example = "")
    private String xreadDuty;

    @ApiModelProperty(value = "阅读人职务",example = "")
    private String xreviewDuty;

    @ApiModelProperty(value = "路由",example = "e151efcc-cb2f-4c6e-a2e1-d98ca6108643")
    private String xroute;

    @ApiModelProperty(value = "目标应用程序",example = "")
    private String xtargetApplication;

    @ApiModelProperty(value = "目标应用程序别名",example = "")
    private String xtargetApplicationAlias;

    @ApiModelProperty(value = "目标应用程序名字",example = "")
    private String xtargetApplicationName;

    @ApiModelProperty(value = "身份",example = "")
    private String xtargetIdentity;

    @ApiModelProperty(value = "选择流程",example = "")
    private String xtargetProcess;

    @ApiModelProperty(value = "选择流程别名",example = "")
    private String xtargetProcessAlias;

    @ApiModelProperty(value = "选择流程名字",example = "")
    private String xtargetProcessName;

    @ApiModelProperty(value = "流程等待",example = "false")
    private Boolean xwaitUntilCompleted;

    @ApiModelProperty(value = "待阅人数据",example = "[]")
    private ArrayList<String> xreadDataPathList;

    @ApiModelProperty(value = "待阅人组织",example = "[]")
    private ArrayList<String> xreadGroupList;

    @ApiModelProperty(value = "待阅人身份",example = "[]")
    private ArrayList<String> xreadIdentityList;

    @ApiModelProperty(value = "待阅人信息",example = "[]")
    private ArrayList<String> xreadUnitList;

    @ApiModelProperty(value = "流程数据",example = "[]")
    private ArrayList<String> xreviewDataPathList;

    @ApiModelProperty(value = "阅读人组织",example = "[]")
    private ArrayList<String> xreviewGroupList;

    @ApiModelProperty(value = "阅读人身份",example = "[]")
    private ArrayList<String> xreviewIdentityList;

    @ApiModelProperty(value = "阅读人信息",example = "[]")
    private ArrayList<String> xreviewUnitList;


}
