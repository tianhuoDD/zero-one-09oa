package com.zeroone.star.project.dto.j5.cmshome;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：获取栏目列表请求实体类
 * </p>
 * @author 陈思蒙
 */
@Data
@ApiModel("获取栏目列表")
public class GetColumnListDTO extends PageDTO {

    @ApiModelProperty(value = "栏目名称")
    private String appName;
}
