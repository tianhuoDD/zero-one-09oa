package com.zeroone.star.project.dto.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("提交回退流程")
public class RollbackDTO {

    @ApiModelProperty(value = "工作日志",required = true)
    private String workLog;

    @ApiModelProperty(value = "处理人标识集合",required = true)
    private List<String> distinguishedNameList;

    @ApiModelProperty(value = "办理意见")
    private String opinion;

}
