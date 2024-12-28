
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("流程发布信息")
public class PublishVO {

    @Alias("xid")
    @ApiModelProperty(value = "唯一标识符")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

//    @Alias("xsequence")
//    @ApiModelProperty(value = "序列号")
//    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty(value = "更新时间")
    private LocalDateTime updateTime;

//    @Alias("xdistributeFactor")
//    @ApiModelProperty(value = "分发因子")
//    private Integer distributeFactor;

    @Alias("xafterArriveScript")
    @ApiModelProperty(value = "到达后脚本")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty(value = "到达后脚本文本")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty(value = "执行后脚本")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty(value = "执行后脚本文本")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty(value = "查询后脚本")
    private String afterInquireScript;

    @Alias("xafterInquireScriptText")
    @ApiModelProperty(value = "查询后脚本文本")
    private String afterInquireScriptText;

    @Alias("xalias")
    @ApiModelProperty(value = "别名")
    private String alias;

    @Alias("xallowReroute")
    @ApiModelProperty(value = "是否允许重新路由")
    private Boolean allowReroute;

    @Alias("xallowRerouteTo")
    @ApiModelProperty(value = "是否允许作为重新路由的目标")
    private Boolean allowRerouteTo;

    @Alias("xauthorDataPathList")
    @ApiModelProperty(value = "作者数据路径列表")
    private String authorDataPathList;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty(value = "到达前脚本")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty(value = "到达前脚本文本")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty(value = "执行前脚本")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty(value = "执行前脚本文本")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty(value = "查询前脚本")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty(value = "查询前脚本文本")
    private String beforeInquireScriptText;

    @Alias("xcategoryId")
    @ApiModelProperty(value = "分类ID")
    private String categoryId;

    @Alias("xcategoryIdDataPath")
    @ApiModelProperty(value = "分类ID数据路径")
    private String categoryIdDataPath;

    @Alias("xcategorySelectType")
    @ApiModelProperty(value = "分类选择类型")
    private String categorySelectType;

    @Alias("xcmsCreatorIdentity")
    @ApiModelProperty(value = "内容管理系统创建者身份")
    private String cmsCreatorIdentity;

    @Alias("xcmsCreatorScript")
    @ApiModelProperty(value = "内容管理系统创建者脚本")
    private String cmsCreatorScript;

    @Alias("xcmsCreatorScriptText")
    @ApiModelProperty(value = "内容管理系统创建者脚本文本")
    private String cmsCreatorScriptText;

    @Alias("xpublishCmsCreatorType")
    @ApiModelProperty(value = "发布的内容管理系统创建者类型")
    private String publishCmsCreatorType;

    @Alias("xdescription")
    @ApiModelProperty(value = "描述")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty(value = "显示日志脚本")
    private String displayLogScript;

    @Alias("xdisplayLogScriptText")
    @ApiModelProperty(value = "显示日志脚本文本")
    private String displayLogScriptText;

    @Alias("xedition")
    @ApiModelProperty(value = "版本")
    private String edition;

    @Alias("xextension")
    @ApiModelProperty(value = "扩展名")
    private String extension;

    @Alias("xform")
    @ApiModelProperty(value = "表单")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty(value = "组")
    private String group;

    @Alias("xinheritAttachment")
    @ApiModelProperty(value = "是否继承附件")
    private Boolean inheritAttachment;

    @Alias("xname")
    @ApiModelProperty(value = "名称")
    private String name;

    @Alias("xnotifyDataPathList")
    @ApiModelProperty(value = "通知数据路径列表")
    private String notifyDataPathList;

    @Alias("xopinionGroup")
    @ApiModelProperty(value = "意见组")
    private String opinionGroup;

    @Alias("xpictureDataPathList")
    @ApiModelProperty(value = "图片数据路径列表")
    private String pictureDataPathList;

    @Alias("xposition")
    @ApiModelProperty(value = "位置")
    private String position;

    @Alias("xprocess")
    @ApiModelProperty(value = "流程")
    private String process;

//    @Alias("xproperties")
    @ApiModelProperty(value = "属性")
    private Object properties;

    @Alias("xpublishTarget")
    @ApiModelProperty(value = "发布目标")
    private String publishTarget;

    @Alias("xreadDuty")
    @ApiModelProperty(value = "阅读职责")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty(value = "阅读脚本")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty(value = "阅读脚本文本")
    private String readScriptText;

    @Alias("xreaderDataPathList")
    @ApiModelProperty(value = "阅读者数据路径列表")
    private String readerDataPathList;

    @Alias("xreviewDuty")
    @ApiModelProperty(value = "审核职责")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty(value = "审核脚本")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty(value = "审核脚本文本")
    private String reviewScriptText;

    @Alias("xroute")
    @ApiModelProperty(value = "路由")
    private String route;

    @Alias("xtargetAssignDataScript")
    @ApiModelProperty(value = "目标分配数据脚本")
    private String targetAssignDataScript;

    @Alias("xtargetAssignDataScriptText")
    @ApiModelProperty(value = "目标分配数据脚本文本")
    private String targetAssignDataScriptText;

    @Alias("xtitleDataPath")
    @ApiModelProperty(value = "标题数据路径")
    private String titleDataPath;

    @Alias("xuseProcessForm")
    @ApiModelProperty(value = "是否使用流程表单")
    private Boolean useProcessForm;



    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;

}
