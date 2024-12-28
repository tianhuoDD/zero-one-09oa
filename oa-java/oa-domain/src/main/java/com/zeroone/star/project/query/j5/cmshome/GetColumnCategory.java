package com.zeroone.star.project.query.j5.cmshome;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：获取栏目列表实体类
 * </p>
 * @author 陈思蒙
 */
@Data
@ApiModel("获取栏目类型实体类")
@TableName("cms_categoryinfo")
public class GetColumnCategory {

    @ApiModelProperty(value = "栏目类型")
    private String appType;
    @ApiModelProperty(value = "数量")
    private Integer count;
}
