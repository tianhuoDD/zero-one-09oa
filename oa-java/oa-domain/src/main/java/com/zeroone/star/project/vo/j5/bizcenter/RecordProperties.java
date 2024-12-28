
package com.zeroone.star.project.vo.j5.bizcenter;

import com.zeroone.star.project.vo.j5.bizcenter.ActivityVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("记录属性对象")
public class RecordProperties {

    @ApiModelProperty(value = "单位级别排序号")
    String unitLevelOrderNumber;

    @ApiModelProperty(value = "单位级别名称")
    String unitLevelName;

    @ApiModelProperty(value = "职务列表")
    List<String> unitDutyList;

    @ApiModelProperty(value = "下一人工节点列表")
    List<ActivityVO> nextManualList;

    @ApiModelProperty(value = "下一人工节点处理人")
    List<String> nextManualTaskIdentityList;

//    @ApiModelProperty(value = "授权来源身份")
//    String empowerFromIdentity;

    @ApiModelProperty(value = "路由名称")
    String routeName;

    @ApiModelProperty(value = "意见")
    String opinion;

    @ApiModelProperty(value = "开始时间")
    LocalDateTime startTime;

    @ApiModelProperty(value = "已用时长")
    Long elapsed;

    @ApiModelProperty(value = "来源分组")
    String fromGroup;

    @ApiModelProperty(value = "来源意见分组")
    String fromOpinionGroup;


}
