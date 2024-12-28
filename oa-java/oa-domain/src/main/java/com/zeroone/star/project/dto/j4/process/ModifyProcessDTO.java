package com.zeroone.star.project.dto.j4.process;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

@Data
@NoArgsConstructor
@Getter
@Setter
@AllArgsConstructor
@ApiModel("修改流程对象")
public class ModifyProcessDTO {
    @ApiModelProperty(value = "id", example = "123456")
    private String xid;

//    @ApiModelProperty(value = "localDateTime", example = "1999-09-12 23:59:59")
//    private DateTime xcreateTime;

    @ApiModelProperty(value = "sequence", example = "sequence")
    private String xsequence;

//    @ApiModelProperty(value = "localDateTime", example = "1999-09-12 23:59:59")
//    private DateTime xupdateTime;

    @ApiModelProperty(value = "distributeFactor", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "afterArriveScript", example = "afterArriveScript")
    private String xafterArriveScript;

    @ApiModelProperty(value = "afterArriveScriptText", example = "afterArriveScriptText")
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

    @ApiModelProperty(value = "alias", example = "alias")
    private String xalias;

    @ApiModelProperty(value = "application", example = "application")
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

    @ApiModelProperty(value = "category", example = "分类1")
    private String xcategory;

    @ApiModelProperty(value = "checkDraft"/*, example = "checkDraft"*/)
    private Boolean xcheckDraft;

    @ApiModelProperty(value = "creatorPerson", example = "创建人")
    private String xcreatorPerson;

    @ApiModelProperty(value = "defaultStartMode", example = "defaultStartMode")
    private String xdefaultStartMode;

    @ApiModelProperty(value = "description", example = "描述信息")
    private String xdescription;

    @ApiModelProperty(value = "edition", example = "edition")
    private String xedition;

    @ApiModelProperty(value = "editionDes", example = "editionDes")
    private String xeditionDes;

    @ApiModelProperty(value = "editionEnable"/*, example = "editionEnable"*/)
    private Boolean xeditionEnable;

    @ApiModelProperty(value = "editionName", example = "editionName")
    private String xeditionName;

    @ApiModelProperty(value = "editionNumber"/*, example = "editionNumber"*/)
    private Double xeditionNumber;


//    @ApiModelProperty(value = "expireType", example = "expireType")
//    private String xexpireType;
//
//    @ApiModelProperty(value = "expireWorkTime"/*, example = "expireWorkTime"*/)
//    private Boolean xexpireWorkTime;

    @ApiModelProperty(value = "icon", example = "icon")
    private String xicon;

    @ApiModelProperty(value = "lastUpdatePerson", example = "lastUpdatePerson")
    private String xlastUpdatePerson;

//    @ApiModelProperty(value = "lastUpdateTime", example = "lastUpdateTime")
//    private DateTime xlastUpdateTime;

    @ApiModelProperty(value = "name", example = "name")
    private String xname;

    @ApiModelProperty(value = "projection", example = "projection")
    private String xprojection;

    @ApiModelProperty(value = "projectionFully"/*, example = "projectionFully"*/)
    private Boolean xprojectionFully;

    @ApiModelProperty(value = "properties", example = "properties")
    private String xproperties;

    @ApiModelProperty(value = "routeNameAsOpinion"/*, example = "routeNameAsOpinion"*/)
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
