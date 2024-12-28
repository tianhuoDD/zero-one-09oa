package com.zeroone.star.project.query.j5.bizcenter;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @program: oa-java
 * @description: 个人创建详情查询实体
 * @author: hamhuo
 * @create: 2024-10-29 22:49
 **/
@Data
public class PpCWorkQuery extends PageQuery {

    @ApiModelProperty(value = "公务流程流转")
    private String keyValue;

    @ApiModelProperty(value = "测试人员@ceshi@P")
    private String person;
}
