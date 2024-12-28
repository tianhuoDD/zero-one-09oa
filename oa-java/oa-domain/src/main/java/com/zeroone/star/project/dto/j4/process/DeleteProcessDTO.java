package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("删除流程对象")
public class DeleteProcessDTO {
    //没准这个DTO也用不上，因为只用传一个id，其实直接用查询参数就好了
    @ApiModelProperty(value="删除流程的主键id")
    public int xid;

}
