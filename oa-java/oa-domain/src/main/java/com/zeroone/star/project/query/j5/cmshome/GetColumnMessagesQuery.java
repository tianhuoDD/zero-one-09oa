package com.zeroone.star.project.query.j5.cmshome;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.List;
import java.util.Map;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("获取栏目信息")
public class GetColumnMessagesQuery extends PageQuery {



    /*
     * 栏目名称
     */
    @ApiModelProperty(value = "appName", example = "通知公告")
    private String name; // app名称

}
