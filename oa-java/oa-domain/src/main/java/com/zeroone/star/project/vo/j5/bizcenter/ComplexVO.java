
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import com.zeroone.star.project.vo.j5.bizcenter.AgentVO;
import com.zeroone.star.project.vo.j5.bizcenter.BeginVO;
import com.zeroone.star.project.vo.j5.bizcenter.CancelVO;
import com.zeroone.star.project.vo.j5.bizcenter.ChoiceVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;


@Data
@ApiModel("流程信息")
public class ComplexVO {

    @ApiModelProperty(value = "流程ID")
    @Alias("xid")
    private String id;

    @ApiModelProperty(value = "流程名称")
    @Alias("xname")
    private String name;

    @ApiModelProperty(value = "流程别名")
    @Alias("xAlias")
    private String Alias;

    @ApiModelProperty(value = "统一活动到达后事件脚本.")
    @Alias("xafterArriveScript")
    private String afterArriveScript;

    @ApiModelProperty(value = "统一活动到达后事件脚本文本.")
    @Alias("xafterArriveScriptText")
    private String afterArriveScriptText;

    @ApiModelProperty(value = "流程启动前事件脚本")
    @Alias("xafterBeginScript")
    private String afterBeginScript;

    @ApiModelProperty(value = "流程启动前事件脚本文本")
    @Alias("xafterBeginScriptText")
    private String afterBeginScriptText;

    @ApiModelProperty(value = "流程结束前事件脚本")
    @Alias("xafterEndScript")
    private String afterEndScript;

    @ApiModelProperty(value = "流程结束前事件脚本文本")
    @Alias("xafterEndScriptText")
    private String afterEndScriptText;

    @ApiModelProperty(value = "统一活动执行后事件脚本.")
    @Alias("xafterExecuteScript")
    private String afterExecuteScript;

    @ApiModelProperty(value = "统一活动执行后事件脚本文本.")
    @Alias("xafterExecuteScriptText")
    private String afterExecuteScriptText;

    @ApiModelProperty(value = "统一路由查询后事件脚本.")
    @Alias("xafterInquireScript")
    private String afterInquireScript;

    @ApiModelProperty(value = "统一路由查询后事件脚本文本.")
    @Alias("xafterInquireScriptText")
    private String afterInquireScriptText;

    @ApiModelProperty(value = "代理列表")
    @Alias("xagentList")
    private List<AgentVO> agentList;

    @ApiModelProperty(value = "流程所属应用")
    @Alias("xapplication")
    private String application;

    @ApiModelProperty(value = "统一活动到达前事件脚本.")
    @Alias("xbeforeArriveScript")
    private String beforeArriveScript;

    @ApiModelProperty(value = "统一活动到达前事件脚本文本.")
    @Alias("xbeforeArriveScriptText")
    private String beforeArriveScriptText;

    @ApiModelProperty(value = "统一活动执行前事件脚本.")
    @Alias("xbeforeExecuteScript")
    private String beforeExecuteScript;

    @ApiModelProperty(value = "统一活动执行前事件脚本文本.")
    @Alias("xbeforeExecuteScriptText")
    private String beforeExecuteScriptText;

    @ApiModelProperty(value = "统一路由查询前事件脚本.")
    @Alias("xbeforeInquireScript")
    private String beforeInquireScript;

    @ApiModelProperty(value = "统一路由查询前事件脚本文本.")
    @Alias("xbeforeInquireScriptText")
    private String beforeInquireScriptText;

    @ApiModelProperty(value = "流程开始节点")
    @Alias("xbegin")
    private BeginVO begin;

    @ApiModelProperty(value = "取消列表")
    @Alias("xcancelList")
    private List<CancelVO> cancelList;

    @ApiModelProperty(value = "是否执行完全映射,在每次流转时会将所有的工作,待办,已办,待阅,已阅,参阅执行全部字段映射,默认false")
    @Alias("xcheckDraft")
    private Boolean checkDraft;

    @ApiModelProperty(value = "选择列表")
    @Alias("xchoiceList")
    private List<ChoiceVO> choiceList;

    @ApiModelProperty(value = "控制器列表")
    @Alias("xcontrollerList")
    private List<String> controllerList;

    @ApiModelProperty(value = "创建时间")
    @Alias("xcreateTime")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "创建者")
    @Alias("xcreatorPerson")
    private String creatorPerson;

    @ApiModelProperty(value = "默认启动方式,默认为instance")
    @Alias("xdefaultStartMode")
    private String defaultStartMode;

    @ApiModelProperty(value = "延时列表")
    @Alias("xdelayList")
    private List<DelayVO> delayList;

    @ApiModelProperty(value = "流程描述")
    @Alias("xdescription")
    private String description;

    @ApiModelProperty(value = "流程id")
    @Alias("xedition")
    private String edition;

    @ApiModelProperty(value = "是否启用流程版本管理")
    @Alias("xeditionEnable")
    private Boolean editionEnable;

    @ApiModelProperty(value = "流程版本名称")
    @Alias("xeditionName")
    private String editionName;

    @ApiModelProperty(value = "流程版本编号")
    @Alias("xeditionNumber")
    private Integer editionNumber;

    @ApiModelProperty(value = "嵌入列表")
    @Alias("xembedList")
    private List<EmbedVO> embedList;

    @ApiModelProperty(value = "流程结束节点")
    @Alias("xendList")
    private List<EndVO> endList;

    @ApiModelProperty(value = "流程过期时间")
    @Alias("xexpireDay")
    private Integer expireDay;

    @ApiModelProperty(value = "过期小时")
    @Alias("xexpireHour")
    private Integer expireHour;

    @ApiModelProperty(value = "流程过期时间类型")
    @Alias("xexpireType")
    private String expireType;

    @ApiModelProperty(value = "流程过期时间是否为工作时间")
    @Alias("xexpireWorkTime")
    private Boolean expireWorkTime;

    @ApiModelProperty(value = "调用列表")
    @Alias("xinvokeList")
    private List<InvokeVO> invokeList;

    @ApiModelProperty(value = "最后的编辑者")
    @Alias("xlastUpdatePerson")
    private String lastUpdatePerson;

    @ApiModelProperty(value = "最后的编辑时间")
    @Alias("xlastUpdateTime")
    private LocalDateTime lastUpdateTime;

    @ApiModelProperty(value = "人工活动列表")
    @Alias("xmanualList")
    private List<ManualVO> manualList;

    @ApiModelProperty(value = "合并列表")
    @Alias("xmergeList")
    private List<MergeVO> mergeList;

    @ApiModelProperty(value = "并行列表")
    @Alias("xparallelList")
    private List<ParallelVO> parallelList;

    @ApiModelProperty(value = "是否执行完全映射,在每次流转时会将所有的工作,待办,已办,待阅,已阅,参阅执行全部字段映射,默认false")
    @Alias("xprojectionFully")
    private Boolean projectionFully;

    @ApiModelProperty(value = "流程属性")
    @Alias("xproperties")
    private Object properties;

    @ApiModelProperty(value = "流程发布列表")
    @Alias("xpublishList")
    private List<PublishVO> publishList;

    @ApiModelProperty(value = "路由列表")
    @Alias("xrouteList")
    private List<RouteVO> routeList;

    @ApiModelProperty(value = "是否使用路由名称作为意见")
    @Alias("xrouteNameAsOpinion")
    private Boolean routeNameAsOpinion;

    @ApiModelProperty(value = "串行阶段")
    @Alias("xserialPhase")
    private String serialPhase;

    @ApiModelProperty(value = "串行纹理")
    @Alias("xserialTexture")
    private String serialTexture;

    @ApiModelProperty(value = "服务列表")
    @Alias("xserviceList")
    private List<ServiceVO> serviceList;

    @ApiModelProperty(value = "拆分列表")
    @Alias("xsplitList")
    private List<SplitVO> splitList;

    @ApiModelProperty(value = "在指定启动时候,允许新建Work的群组")
    @Alias("xstartableGroupList")
    private List<String> startableGroupList;

    @ApiModelProperty(value = "在指定启动时候,允许新建Work的用户")
    @Alias("xstartableIdentityList")
    private List<String> startableIdentityList;

    @ApiModelProperty(value = "可启动流程终端类型,可选值 client,mobile,all,none")
    @Alias("xstartableTerminal")
    private String startableTerminal;

    @ApiModelProperty(value = "在指定启动时候,允许新建Work的组织")
    @Alias("xstartableUnitList")
    private List<String> startableUnitList;

    @ApiModelProperty(value = "修改时间")
    @Alias("xupdateTime")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "流程分类")
    @Alias("xcategory")
    private String category;

    @ApiModelProperty(value = "icon Base64编码后的文本.")
    @Alias("xicon")
    private String icon;

    @ApiModelProperty(value = "编号活动ID")
    @Alias("xserialActivity")
    private String serialActivity;

    @ApiModelProperty(value = "字段映射配置.")
    @Alias("xprojection")
    private String projection;

    @ApiModelProperty(value = "版本描述.")
    @Alias("xeditionDes")
    private String editionDes;
}
