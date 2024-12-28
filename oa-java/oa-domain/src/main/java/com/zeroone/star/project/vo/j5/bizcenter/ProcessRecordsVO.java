package com.zeroone.star.project.vo.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */
@ApiModel("流程记录数据")
@Data
public class ProcessRecordsVO {
    @ApiModelProperty(value = "流转标题",example = "会议申请")
    private String processTitle;
    @ApiModelProperty(value = "处理人",example = "开发部员工")
    private String processors;
    @ApiModelProperty(value = "处理意见",example = "同意")
    private String handlingComments;
    @ApiModelProperty(value = "流程结束日期",example = "2021-09-01 17:14")
    private Date processDate;
}
