package com.zeroone.star.project.vo.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("删除流程对象向前端返回的VO")
public class DeleteProcessVO {

    @ApiModelProperty(value="删除流程的主键id")
    public String xid;

}
