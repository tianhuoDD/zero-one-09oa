package com.zeroone.star.project.query.j5.bizcenter;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @program: oa-java
 * @description: 已阅查询实体
 * @author: hamhuo
 * @create: 2024-10-29 22:13
 **/
@Data
@ApiModel(value = "已阅事项查询对象")
public class PpCReadcompletedQuery extends PageQuery {

    @ApiModelProperty(value = "审计局报告草稿")
    private String keyValue;

    @ApiModelProperty(value = "测试人员@ceshi@P")
    private String person;
}
