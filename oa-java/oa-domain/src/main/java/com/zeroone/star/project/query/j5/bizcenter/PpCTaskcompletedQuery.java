package com.zeroone.star.project.query.j5.bizcenter;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @program: oa-java
 * @description: 待办事项查询对象(封装和分页)
 * @author: hamhuo
 * @create: 2024-10-27 17:14
 **/
@Data
@ApiModel(value = "已办事项查询对象")
public class PpCTaskcompletedQuery extends PageQuery {

    @ApiModelProperty(value = "公务流程流转")
    private String keyValue;

    @ApiModelProperty(value = "测试人员@ceshi@P")
    private String person;
}
