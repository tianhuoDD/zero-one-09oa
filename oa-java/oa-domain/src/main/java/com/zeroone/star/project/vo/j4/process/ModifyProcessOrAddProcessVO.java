package com.zeroone.star.project.vo.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("修改流程对象或者删除流程对象向前端返回的VO")
public class ModifyProcessOrAddProcessVO {
    @ApiModelProperty(value = "流程的主键id")
    public String xid;

}
