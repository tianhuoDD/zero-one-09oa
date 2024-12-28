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
@ApiModel("开始活动数据对象")
public class PublishDTO {

    @ApiModelProperty(value = "主键ID",example = "cc88613a-637d-41fb-ace6-8f4ba4a0063b")
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

    @ApiModelProperty(value = "数据",example = "")
    private String xauthorDataPathList;

    @ApiModelProperty(value = "分类",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xcategoryId;

    @ApiModelProperty(value = "内容管理分类数据路径",example = "1")
    private String xcategoryIdDataPath;

    @ApiModelProperty(value = "内容管理分类:",example = "dataPath")
    private String xcategorySelectType;

    @ApiModelProperty(value = "描述信息",example = "")
    private String xdescription;

    @ApiModelProperty(value = "版本信息",example = "CAF272ECC55000017BFBE6801DBB7650")
    private String xedition;

    @ApiModelProperty(value = "延伸信息",example = "")
    private String xextension;

    @ApiModelProperty(value = "表单信息",example = "")
    private String xform;

    @ApiModelProperty(value = "开关",example = "true")
    private Boolean xinheritAttachment;

    @ApiModelProperty(value = "名字",example = "取消")
    private String xname;

    @ApiModelProperty(value = "消息推送范围字段::",example = "publishFor")
    private ArrayList<String> xnotifyDataPathList;

    @ApiModelProperty(value = "首页图片字段::",example = "imageclipper")
    private ArrayList<String> xpictureDataPathList;

    @ApiModelProperty(value = "位置信息",example = "680,160")
    private String xposition;

    @ApiModelProperty(value = "流程信息",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xprocess;

    @ApiModelProperty(value = "属性",example = "{}")
    private ArrayList<String> xproperties;

    @ApiModelProperty(value = "发布目标",example = "cms")
    private String xpublishTarget;

    @ApiModelProperty(value = "待阅人职务",example = "")
    private String xreadDuty;

    @ApiModelProperty(value = "读者字段",example = "publishFor")
    private ArrayList<String> xreaderDataPathList;

    @ApiModelProperty(value = "阅读人职务",example = "")
    private String xreviewDuty;

    @ApiModelProperty(value = "路由",example = "")
    private String xroute;

    @ApiModelProperty(value = "标题字段",example = "subject")
    private String xtitleDataPath;

    @ApiModelProperty(value = "使用流程表单",example = "false")
    private Boolean xuseProcessForm;

    @ApiModelProperty(value = "流程数据",example = "[]")
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
