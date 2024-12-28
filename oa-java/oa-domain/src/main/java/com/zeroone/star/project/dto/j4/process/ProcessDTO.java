package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.ArrayList;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("流程对象")
public class ProcessDTO {

    @ApiModelProperty(value = "流程的别名",example = "别名1")
    public String xalias;

    @ApiModelProperty(value = "流程所属应用",example = "应用1")
    public String xapplication;

    @ApiModelProperty(value = "流程所属应用的名字",example = "应用名字1")
    public String xapplicationName;

    @ApiModelProperty(value = "流程串行纹理",example = "[]")
    public String xserialTexture;

    @ApiModelProperty(value = "流程所属分类",example = "分类1")
    public String xcategory;

    @ApiModelProperty(value = "流程检查草稿有无",example = "true")
    public Boolean xcheckDraft;

    @ApiModelProperty(value = "流程的创建时间",example = "2024-10-24 21:21:33")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    public Date xcreateTime;

    @ApiModelProperty(value = "流程创建者",example = "张三")
    public String xcreatorPerson;

    @ApiModelProperty(value = "默认启动模式",example = "启动模式1")
    public String xdefaultStartMode;

    @ApiModelProperty(value = "流程描述信息",example = "这是个请假流程")
    public String xdescription;

    @ApiModelProperty(value = "流程版本信息",example = "512804d6-a18d-4db3-a883-79a27d8d1323")
    public String xedition;

    @ApiModelProperty(value = "流程版本描述信息",example = "我看看怎么个事")
    public String xeditionDes;

    @ApiModelProperty(value = "流程版本开关,0表示关，1表示开",example = "true")
    public Boolean xeditionEnable;

    @ApiModelProperty(value = "流程预期天数",example = "7")
    public int xexpireDay;

    @ApiModelProperty(value = "流程预期小时数",example = "1")
    public int xexpireHour;

    @ApiModelProperty(value = "流程预期类型",example = "never")
    public String xexpireType;

    @ApiModelProperty(value = "流程预期时间，true表示有预期，false表示没有",example = "false")
    public Boolean xexpireWorkTime;

    @ApiModelProperty(value = "流程图标",example = "../x_component_process_ProcessManager/$Explorer/default/processIcon/process_icon_1.png")
    public String xicon;

    @ApiModelProperty(value = "流程Id，也就是主键，即唯一标识",example = "17204098-a2b1-403a-9869-146991c478b2")
    public String xid;

    @ApiModelProperty(value = "最后一个更新流程的人",example = "李四")
    public String xlastUpdatePerson;

    @ApiModelProperty(value = "流程的最后更新时间",example = "2024-10-27 01:41:04")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    public Date xlastUpdateTime;

    @ApiModelProperty(value = "流程维护人",example = "王五")
    public String xmaintenanceIdentity;

    @ApiModelProperty(value = "流程名字",example = "流程1")
    public String xname;

    @ApiModelProperty(value = "管理者脚本",example = "Hello World")
    public String xpermissionWriteScript;

    @ApiModelProperty(value = "路由信息",example = "false")
    public Boolean xrouteNameAsOpinion;

    @ApiModelProperty(value = "流程串行相位",example = "arrive")
    public String xserialPhase;

    @ApiModelProperty(value = "属性",example = "")
    public String xproperties;

    @ApiModelProperty(value = "流程可启动终端",example = "all")
    public String xstartableTerminal;

    @ApiModelProperty(value = "流程的启动组织")
    public String xstartableGroupList;

    @ApiModelProperty(value = "流程的启动人")
    public String xstartableIdentityList;

    @ApiModelProperty(value = "流程的启动群组")
    public String xstartableUnitList;

    @ApiModelProperty(value = "流程的版本")
    public String xversionDescription;

}
