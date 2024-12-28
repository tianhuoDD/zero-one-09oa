package com.zeroone.star.project.query.j5.bizcenter;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;

/**
 * @program: oa-java
 * @description: 待阅查询对象
 * @author: hamhuo
 * @create: 2024-10-29 15:53
 **/
@Data
public class PpCReadQuery extends PageQuery {
    @ApiModelProperty(value = "测试待阅对象")
    private String keyValue;

    @ApiModelProperty(value = "测试人员@ceshi@P")
    private String person;
}
