package com.zeroone.star.project.j3.ColumnAttribute.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.List;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author KO
 */
@Data
@ApiModel(description = "CMS表栏目可见范围对象")
public class ColumnViewableListDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "栏目标识",example = "1")
    private String xid;

    @ApiModelProperty(value = "可见范围",example = "[\"admin\"]")
    private List<String> xviewablePersonList;


}
