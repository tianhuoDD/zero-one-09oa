package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("修改流程对象")
public class ModifyProcessOrAddProcessDTO {

    @ApiModelProperty(value = "流程本身数据",example = "")
    public ProcessDTO processDTO;

    @ApiModelProperty(value = "脚本活动数据列表,里面可能存在多个脚本活动的数据",example = "[{xid: \"c967390c-3687-40e2-8abf-2a5caf48cee5\", xname: \"脚本\", xalias: \"\", xdescription: \"\",xallowReroute:0,xallowRerouteTo:1,xcreateTime:\"2024-10-24 21:21:33\"},xdescription:\"\",xedition:\"CAF274795AC00001D81F16531DB017E0\",xextension:\"\",xform:\"\",xid:\"c967390c-3687-40e2-8abf-2a5caf48cee5\",xname:\"脚本\",xposition:\"850,170\",xprocess:\"17204098-a2b1-403a-9869-146991c478b2\",xproperties:\"\",xreadDuty:\"局长\",xreviewDuty:\"局长\",xroute:\"37bb59ef-7270-4f76-8163-6c531d3e44b8\",xupdateTime:\"2024-10-27 10:17:35\"}]")
    public ArrayList<AgentDTO> agentList;

    @ApiModelProperty(value = "流程的开始活动信息")
    public BeginDTO beginDTO;

    @ApiModelProperty(value = "流程的结束活动信息")
    public ArrayList<CancelDTO> cancelList;

    @ApiModelProperty(value = "流程的选择活动信息")
    public ArrayList<ChoiceDTO> choiceList;

    @ApiModelProperty(value = "流程的管理者",example = "[\"荒天帝\",\"萧炎\"]")
    public ArrayList<String> controllerList;

    @ApiModelProperty(value = "流程的定时活动信息")
    public ArrayList<DelayDTO> delayList;

    @ApiModelProperty(value = "流程调用的数据信息")
    public ArrayList<EmbedDTO> embedList;

    @ApiModelProperty(value = "结束活动的数据信息")
    public ArrayList<EndDTO> endList;

    @ApiModelProperty(value = "服务调用的数据信息")
    public ArrayList<InvokeDTO> invokeList;

    @ApiModelProperty(value = "人工活动的数据信息")
    public ArrayList<ManualDTO> manualList;

    @ApiModelProperty(value = "合并活动的数据信息")
    public ArrayList<MergeDTO> mergeList;

    @ApiModelProperty(value = "并行活动的数据信息")
    public ArrayList<ParallelDTO> parallelList;

    @ApiModelProperty(value = "数据发布的数据信息")
    public ArrayList<PublishDTO> publishList;

    @ApiModelProperty(value = "路由表")
    public ArrayList<RouteDTO> routeList;

    @ApiModelProperty(value = "服务活动的数据信息")
    public ArrayList<ServiceDTO> serviceList;

    @ApiModelProperty(value = "拆分活动的数据信息")
    public ArrayList<SplitDTO> splitList;

}










