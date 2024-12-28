
package com.zeroone.star.project.vo.j5.bizcenter;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 类PpEEndVO表示流程结束节点的属性和配置信息。该类用于在系统中定义和管理流程结束时的行为和特性。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Data
@ApiModel("流程结束节点属性和配置信息")
public class EndVO {



    @ApiModelProperty(value = "唯一标识符，用于标识特定对象")
    private String id;

    @ApiModelProperty(value = "创建时间，记录对象创建的时间点")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "序列号，用于对象的排序或序列组织")
    private String sequence;

    @ApiModelProperty(value = "更新时间，记录对象最近一次更新的时间点")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "分发因子，用于对象的分发或路由决策")
    private Integer distributeFactor;

    @ApiModelProperty(value = "到达后脚本标识，指示到达特定状态后执行的脚本")
    private String afterArriveScript;

    @ApiModelProperty(value = "到达后脚本文本，包含实际执行的脚本内容")
    private String afterArriveScriptText;

    @ApiModelProperty(value = "执行后脚本标识，指示执行特定操作后运行的脚本")
    private String afterExecuteScript;

    @ApiModelProperty(value = "执行后脚本文本，包含实际执行的脚本内容")
    private String afterExecuteScriptText;

    @ApiModelProperty(value = "查询后脚本标识，指示查询操作后执行的脚本")
    private String afterInquireScript;

    @ApiModelProperty(value = "查询后脚本文本，包含实际执行的脚本内容")
    private String afterInquireScriptText;

    @ApiModelProperty(value = "别名，为对象提供一个易于读取的名称")
    private String alias;

    @ApiModelProperty(value = "是否允许重新路由，指示对象是否可以被重新路由")
    private Boolean allowReroute;

    @ApiModelProperty(value = "是否允许作为重新路由目标，指示对象是否可以成为其他对象的重新路由目标")
    private Boolean allowRerouteTo;

    @ApiModelProperty(value = "到达前脚本标识，指示到达特定状态前执行的脚本")
    private String beforeArriveScript;

    @ApiModelProperty(value = "到达前脚本文本，包含实际执行的脚本内容")
    private String beforeArriveScriptText;

    @ApiModelProperty(value = "执行前脚本标识，指示执行特定操作前运行的脚本")
    private String beforeExecuteScript;

    @ApiModelProperty(value = "执行前脚本文本，包含实际执行的脚本内容")
    private String beforeExecuteScriptText;

    @ApiModelProperty(value = "查询前脚本标识，指示查询操作前执行的脚本")
    private String beforeInquireScript;

    @ApiModelProperty(value = "查询前脚本文本，包含实际执行的脚本内容")
    private String beforeInquireScriptText;

    @ApiModelProperty(value = "描述，提供对象的详细描述信息")
    private String description;

    @ApiModelProperty(value = "显示日志脚本标识，指示用于显示日志信息的脚本")
    private String displayLogScript;

    @ApiModelProperty(value = "显示日志脚本文本，包含实际执行的脚本内容")
    private String displayLogScriptText;

    @ApiModelProperty(value = "版本，表示对象的当前版本号")
    private String edition;

    @ApiModelProperty(value = "扩展信息，用于存储附加的可扩展属性")
    private String extension;

    @ApiModelProperty(value = "表单标识，关联对象与特定的表单")
    private String form;

    @ApiModelProperty(value = "组标识，将对象归类到特定的组")
    private String group;

    @ApiModelProperty(value = "名称，提供对象的名称")
    private String name;

    @ApiModelProperty(value = "意见组，用于收集或归类意见")
    private String opinionGroup;

    @ApiModelProperty(value = "位置，指示对象的位置或场所")
    private String position;

    @ApiModelProperty(value = "流程标识，关联对象与特定的流程")
    private String process;

    @ApiModelProperty(value = "属性，包含对象的自定义属性信息")
    private String properties;

    @ApiModelProperty(value = "读取职责，定义谁可以读取对象信息")
    private String readDuty;

    @ApiModelProperty(value = "读取数据路径列表")
    private List<String> readDataPathList;

    @ApiModelProperty(value = "读取组列表")
    private List<String> readGroupList;

    @ApiModelProperty(value = "读取身份列表")
    private List<String> readIdentityList;

    @ApiModelProperty(value = "读取单位列表")
    private List<String> readUnitList;

    @ApiModelProperty(value = "审核数据路径列表")
    private List<String> reviewDataPathList;

    @ApiModelProperty(value = "审核组列表")
    private List<String> reviewGroupList;

    @ApiModelProperty(value = "审核身份列表")
    private List<String> reviewIdentityList;

    @ApiModelProperty(value = "审核单位列表")
    private List<String> reviewUnitList;

    @ApiModelProperty(value = "读取脚本标识，指示用于读取操作的脚本")
    private String readScript;

    @ApiModelProperty(value = "读取脚本文本，包含实际执行的脚本内容")
    private String readScriptText;

    @ApiModelProperty(value = "审核职责，定义谁可以审核对象")
    private String reviewDuty;

    @ApiModelProperty(value = "审核脚本标识，指示用于审核操作的脚本")
    private String reviewScript;

    @ApiModelProperty(value = "审核脚本文本，包含实际执行的脚本内容")
    private String reviewScriptText;
}
