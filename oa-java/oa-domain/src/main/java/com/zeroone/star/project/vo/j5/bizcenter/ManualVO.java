
package com.zeroone.star.project.vo.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("人工活动信息")
public class ManualVO {
    @ApiModelProperty(value = "统一活动到达后事件脚本.")
    private String afterArriveScript;

    @ApiModelProperty(value = "统一活动到达后事件脚本文本.")
    private String afterArriveScriptText;

    @ApiModelProperty(value = "统一活动执行后事件脚本.")
    private String afterExecuteScript;

    @ApiModelProperty(value = "统一活动执行后事件脚本文本.")
    private String afterExecuteScriptText;

    @ApiModelProperty(value = "统一路由查询后事件脚本.")
    private String afterInquireScript;

    @ApiModelProperty(value = "统一路由查询后事件脚本文本.")
    private String afterInquireScriptText;

    @ApiModelProperty(value = "别名")
    private String alias;

    @ApiModelProperty(value = "是否允许拆分")
    private Boolean allowAddSplit;

    @ApiModelProperty(value = "是否允许删除工作")
    private Boolean allowDeleteWork;

    @ApiModelProperty(value = "是否允许暂停")
    private Boolean allowPause;

    @ApiModelProperty(value = "是否允许处理")
    private Boolean allowPress;

    @ApiModelProperty(value = "是否允许快速处理")
    private Boolean allowRapid;

    @ApiModelProperty(value = "是否允许重新路由")
    private Boolean allowReroute;

    @ApiModelProperty(value = "是否允许重新路由到")
    private Boolean allowRerouteTo;

    @ApiModelProperty(value = "是否允许重新重置")
    private Boolean allowReset;

    @ApiModelProperty(value = "是否允许回退")
    private Boolean allowRetract;

    @ApiModelProperty(value = "是否允许回滚")
    private Boolean allowRollback;

    @ApiModelProperty(value = "统一活动到达前事件脚本.")
    private String beforeArriveScript;

    @ApiModelProperty(value = "统一活动到达前事件脚本文本.")
    private String beforeArriveScriptText;

    @ApiModelProperty(value = "统一活动执行前事件脚本.")
    private String beforeExecuteScript;

    @ApiModelProperty(value = "统一活动执行前事件脚本文本.")
    private String beforeExecuteScriptText;

    @ApiModelProperty(value = "统一路由查询前事件脚本.")
    private String beforeInquireScript;

    @ApiModelProperty(value = "统一路由查询前事件脚本文本.")
    private String beforeInquireScriptText;

    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "描述")
    private String description;

    @ApiModelProperty(value = "启用")
    private String enable;

    @ApiModelProperty(value = "扩展信息")
    private String extension;

    @ApiModelProperty(value = "")
    private String form;

    @ApiModelProperty(value = "回退配置")
    private Object goBackConfig;

    @ApiModelProperty(value = "组")
    private String group;

    @ApiModelProperty(value = "id")
    private String id;

    @ApiModelProperty(value = "任务后人工活动脚本")
    private String manualAfterTaskScript;

    @ApiModelProperty(value = "任务后人工活动脚本文本")
    private String manualAfterTaskScriptText;

    @ApiModelProperty(value = "任务前人工活动脚本")
    private String manualBeforeTaskScript;

    @ApiModelProperty(value = "任务前人工活动脚本文本")
    private String manualBeforeTaskScriptText;

    @ApiModelProperty(value = "是否合并相同任务")
    private Boolean manualMergeSameJobActivity;

    @ApiModelProperty(value = "人工活动模式")
    private String manualMode;

    @ApiModelProperty(value = "人工停留脚本")
    private String manualStayScript;

    @ApiModelProperty(value = "人工停留脚本文本")
    private String manualStayScriptText;

    @ApiModelProperty(value = "是否手动读取未完成的任务")
    private Boolean manualUncompletedTaskToRead;

    @ApiModelProperty(value = "名称")
    private String name;

    @ApiModelProperty(value = "意见分组")
    private String opinionGroup;

    @ApiModelProperty(value = "位置")
    private String position;

    @ApiModelProperty(value = "流程id")
    private String process;

    @ApiModelProperty(value = "是否同一人处理同一任务")
    private Boolean processingTaskOnceUnderSamePerson;

    @ApiModelProperty(value = "属性")
    private Object properties;


    @ApiModelProperty(value = "阅读人数据路径")
    private List<String> readDataPathList;

    @ApiModelProperty(value = "阅读人职务")
    private String readDuty;

    @ApiModelProperty(value = "阅读人分组")
    private List<String> readGroupList;

    @ApiModelProperty(value = "阅读人身份")
    private List<String> readIdentityList;

    @ApiModelProperty(value = "阅读人脚本")
    private String readScript;

    @ApiModelProperty(value = "阅读人脚本文本")
    private String readScriptText;

    @ApiModelProperty(value = "阅读人单位")
    private List<String> readUnitList;

    @ApiModelProperty(value = "重置次数")
    private Integer resetCount;

    @ApiModelProperty(value = "重置范围")
    private String resetRange;

    @ApiModelProperty(value = "审核数据路径")
    private List<String> reviewDataPathList;

    @ApiModelProperty(value = "审核职务")
    private String reviewDuty;

    @ApiModelProperty(value = "审核分组")
    private List<String> reviewGroupList;

    @ApiModelProperty(value = "审核身份")
    private List<String> reviewIdentityList;

    @ApiModelProperty(value = "审核脚本")
    private String reviewScript;

    @ApiModelProperty(value = "审核脚本文本")
    private String reviewScriptText;

    @ApiModelProperty(value = "审核单位")
    private List<String> reviewUnitList;

    @ApiModelProperty(value = "路由")
    private List<String> routeList;

    @ApiModelProperty(value = "任务数据路径")
    private List<String> taskDataPathList;

    @ApiModelProperty(value = "任务职务")
    private String taskDuty;

    @ApiModelProperty(value = "任务过期天数")
    private Integer taskExpireDay;

    @ApiModelProperty(value = "任务过期小时")
    private Integer taskExpireHour;

    @ApiModelProperty(value = "任务过期类型")
    private String taskExpireType;

    @ApiModelProperty(value = "任务过期是否计算工作日")
    private Boolean taskExpireWorkTime;

    @ApiModelProperty(value = "任务分组")
    private List<String> taskGroupList;

    @ApiModelProperty(value = "任务身份")
    private List<String> taskIdentityList;

    @ApiModelProperty(value = "任务脚本")
    private String taskScript;

    @ApiModelProperty(value = "任务脚本文本")
    private String taskScriptText;

    @ApiModelProperty(value = "任务单位")
    private List<String> taskUnitList;

    @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;

}

