package com.zeroone.star.project.query.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */

@Data
@ApiModel("流程管理查询条件对象")
public class ProcessManagementQuery {
    @ApiModelProperty(value = "流转标题",example = "会议申请")
    private String processTitle;

}
