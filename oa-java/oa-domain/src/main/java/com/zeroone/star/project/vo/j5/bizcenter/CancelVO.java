
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("流程取消信息")
public class CancelVO {

    @Alias("xid")
    @ApiModelProperty("流程取消事件的唯一标识符")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty("创建流程取消事件的时间")
    private LocalDateTime createTime;


    @ApiModelProperty("流程取消事件的序列号")
    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty("最后一次更新流程取消事件的时间")
    private LocalDateTime updateTime;


    @ApiModelProperty("分发因子，用于确定事件的处理优先级或顺序")
    private Integer distributeFactor;

    @Alias("xafterArriveScript")
    @ApiModelProperty("到达后执行的脚本，用于处理特定的业务逻辑")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty("到达后执行脚本的文本内容")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty("执行后执行的脚本，用于处理特定的业务逻辑")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty("执行后执行脚本的文本内容")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty("查询后执行的脚本，用于处理特定的业务逻辑")
    private String afterInquireScript;

    @Alias("xafterInquireScriptText")
    @ApiModelProperty("查询后执行脚本的文本内容")
    private String afterInquireScriptText;

    @Alias("xalias")
    @ApiModelProperty("流程取消事件的别名")
    private String alias;

    @Alias("xallowReroute")
    @ApiModelProperty("是否允许重新路由")
    private Boolean allowReroute;

    @Alias("xallowRerouteTo")
    @ApiModelProperty("是否允许作为重新路由的目标")
    private Boolean allowRerouteTo;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty("到达前执行的脚本，用于处理特定的业务逻辑")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty("到达前执行脚本的文本内容")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty("执行前执行的脚本，用于处理特定的业务逻辑")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty("执行前执行脚本的文本内容")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty("查询前执行的脚本，用于处理特定的业务逻辑")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty("查询前执行脚本的文本内容")
    private String beforeInquireScriptText;

    @Alias("xdescription")
    @ApiModelProperty("流程取消事件的描述")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty("显示日志的脚本，用于记录和展示日志信息")
    private String displayLogScript;

    @Alias("xdisplayLogScriptText")
    @ApiModelProperty("显示日志脚本的文本内容")
    private String displayLogScriptText;

    @Alias("xedition")
    @ApiModelProperty("流程取消事件的版本号")
    private String edition;

    @Alias("xextension")
    @ApiModelProperty("扩展信息，用于存储附加的数据或配置")
    private String extension;

    @Alias("xform")
    @ApiModelProperty("表单标识，关联到特定的表单")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty("组标识，用于将事件归类到特定的组")
    private String group;

    @Alias("xname")
    @ApiModelProperty("流程取消事件的名称")
    private String name;

    @Alias("xopinionGroup")
    @ApiModelProperty("意见组标识，用于关联到特定的意见组")
    private String opinionGroup;

    @Alias("xposition")
    @ApiModelProperty("位置标识，指示事件发生的位置")
    private String position;

    @Alias("xprocess")
    @ApiModelProperty("流程标识，关联到特定的流程")
    private String process;


    @ApiModelProperty("属性信息，存储事件的附加属性")
    private Object properties;

    @Alias("xreadDuty")
    @ApiModelProperty("读取职责，定义谁可以读取事件信息")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty("读取时执行的脚本，用于处理读取操作时的特定逻辑")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty("读取脚本的文本内容")
    private String readScriptText;

    @Alias("xreviewDuty")
    @ApiModelProperty("审核职责，定义谁可以审核事件")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty("审核时执行的脚本，用于处理审核操作时的特定逻辑")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty("审核脚本的文本内容")
    private String reviewScriptText;


    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;



}
