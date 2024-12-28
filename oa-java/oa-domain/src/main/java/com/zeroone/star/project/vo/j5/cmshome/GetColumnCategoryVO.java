package com.zeroone.star.project.vo.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：获取栏目列表响应实体类
 * </p>
 * @author 陈思蒙
 */
@Data
@ApiModel("获取栏目列表")
public class GetColumnCategoryVO {

    @ApiModelProperty(value = "栏目类型")
    private String appType;
    @ApiModelProperty(value = "数量")
    private Integer count;
}
