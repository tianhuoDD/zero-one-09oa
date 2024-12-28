package com.zeroone.star.project.query.meeting;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;


@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("示例查询对象")
public class MeetingQuery extends PageQuery {
    @NotBlank(message = "用户名不能为空")
    @ApiModelProperty(value = "创建者", example = "张三")
    private String xauditor;
}
