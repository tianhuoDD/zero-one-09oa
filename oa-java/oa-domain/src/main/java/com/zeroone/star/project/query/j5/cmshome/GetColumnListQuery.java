package com.zeroone.star.project.query.j5.cmshome;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@EqualsAndHashCode(callSuper = false)
@Data
@ApiModel("获取文档列表")
public class GetColumnListQuery extends PageQuery {


    /*
     * 栏目名称
     */
    @ApiModelProperty(value = "栏目id", example = "通知公告")
    private String name; // 查询的栏目id


}
