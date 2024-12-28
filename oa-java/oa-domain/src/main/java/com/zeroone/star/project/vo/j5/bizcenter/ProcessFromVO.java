package com.zeroone.star.project.vo.j5.bizcenter;

import com.zeroone.star.project.dto.j5.bizcenter.ProcessFromDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@ApiModel("流程表单对象")
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class ProcessFromVO {
    @ApiModelProperty("流程表单数据对象")
    private ProcessFromDTO form;

    @ApiModelProperty("URL的tag，用来标示URL对象是否改变")
    private String fastETag;
}
