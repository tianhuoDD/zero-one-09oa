package com.zeroone.star.project.vo.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("流程显示对象")
public class PpEProcessVO {

    @ApiModelProperty(value = "标识", example = "123456")
    private String xid;

    @ApiModelProperty(value = "创建时间", example = "2024-10-08 23:59:59")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "顺序号", example = "sequence")
    private String xsequence;

    @ApiModelProperty(value = "更新时间", example = "1999-09-12 23:59:59")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "distributeFactor", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "afterArrive脚本", example = "底下后缀均类似但不清楚具体")
    private String xafterArriveScript;

    @ApiModelProperty(value = "afterArrive脚本文件", example = "afterArriveScriptText")
    private String xafterArriveScriptText;

    @ApiModelProperty(value = "afterBeginScript", example = "afterBeginScript")
    private String xafterBeginScript;

    @ApiModelProperty(value = "afterBeginScriptText", example = "afterBeginScriptText")
    private String xafterBeginScriptText;

    @ApiModelProperty(value = "afterEndScript", example = "afterEndScript")
    private String xafterEndScript;

    @ApiModelProperty(value = "afterEndScriptText", example = "afterEndScriptText")
    private String xafterEndScriptText;

    @ApiModelProperty(value = "afterExecuteScript", example = "afterExecuteScript")
    private String xafterExecuteScript;

    @ApiModelProperty(value = "afterExecuteScriptText", example = "afterExecuteScriptText")
    private String xafterExecuteScriptText;

    @ApiModelProperty(value = "afterInquireScript", example = "afterInquireScript")
    private String xafterInquireScript;

    @ApiModelProperty(value = "afterInquireScriptText", example = "afterInquireScriptText")
    private String xafterInquireScriptText;

    @ApiModelProperty(value = "别名", example = "小流程~")
    private String xalias;

    @ApiModelProperty(value = "应用", example = "应用1")
    private String xapplication;

    @ApiModelProperty(value = "beforeArriveScript", example = "beforeArriveScript")
    private String xbeforeArriveScript;

    @ApiModelProperty(value = "beforeArriveScriptText", example = "beforeArriveScriptText")
    private String xbeforeArriveScriptText;

    @ApiModelProperty(value = "beforeExecuteScript", example = "beforeExecuteScript")
    private String xbeforeExecuteScript;

    @ApiModelProperty(value = "beforeExecuteScriptText", example = "beforeExecuteScriptText")
    private String xbeforeExecuteScriptText;

    @ApiModelProperty(value = "beforeInquireScript", example = "beforeInquireScript")
    private String xbeforeInquireScript;

    @ApiModelProperty(value = "beforeInquireScriptText", example = "beforeInquireScriptText")
    private String xbeforeInquireScriptText;

    @ApiModelProperty(value = "分类", example = "类别1")
    private String xcategory;

    @ApiModelProperty(value = "checkDraft", example = "checkDraft")
    private Boolean xcheckDraft;

    @ApiModelProperty(value = "创建人", example = "戴夫")
    private String xcreatorPerson;

    @ApiModelProperty(value = "defaultStartMode", example = "defaultStartMode")
    private String xdefaultStartMode;

    @ApiModelProperty(value = "描述", example = "好，很好！很有精神！")
    private String xdescription;

    @ApiModelProperty(value = "edition", example = "edition")
    private String xedition;

    @ApiModelProperty(value = "editionDes", example = "editionDes")
    private String xeditionDes;

    @ApiModelProperty(value = "editionEnable", example = "editionEnable")
    private Boolean xeditionEnable;

    @ApiModelProperty(value = "editionName", example = "editionName")
    private String xeditionName;

    @ApiModelProperty(value = "editionNumber", example = "1")
    private Double xeditionNumber;

    @ApiModelProperty(value = "到期日", example = "1")
    private Integer xexpireDay;

    @ApiModelProperty(value = "到期小时", example = "1")
    private Integer xexpireHour;

    @ApiModelProperty(value = "到期类型", example = "expireType")
    private String xexpireType;

    @ApiModelProperty(value = "截至到期工作时间", example = "true")
    private Boolean xexpireWorkTime;

    @ApiModelProperty(value = "图标", example = "https://tse3-mm.cn.bing.net/th/id/OIP-C.QUbrm8dICaen_1SEJkaFoQHaGv?rs=1&pid=ImgDetMain")
    private String xicon;

    @ApiModelProperty(value = "最后更新人", example = "张三")
    private String xlastUpdatePerson;

    @ApiModelProperty(value = "最后更新时间", example = "2024-10-22 10:25:25")
    private LocalDateTime xlastUpdateTime;

    @ApiModelProperty(value = "名称", example = "流程1")
    private String xname;

    @ApiModelProperty(value = "projection", example = "projection")
    private String xprojection;

    @ApiModelProperty(value = "projectionFully", example = "true")
    private Boolean xprojectionFully;

    @ApiModelProperty(value = "属性", example = "属性")
    private String xproperties;

    @ApiModelProperty(value = "routeNameAsOpinion", example = "true")
    private Boolean xrouteNameAsOpinion;

    @ApiModelProperty(value = "serialActivity", example = "serialActivity")
    private String xserialActivity;

    @ApiModelProperty(value = "serialPhase", example = "serialPhase")
    private String xserialPhase;

    @ApiModelProperty(value = "serialTexture", example = "serialTexture")
    private String xserialTexture;

    @ApiModelProperty(value = "startableTerminal", example = "startableTerminal")
    private String xstartableTerminal;

}
