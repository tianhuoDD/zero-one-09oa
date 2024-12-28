package com.zeroone.star.project.j3.ColumnAttribute.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

import java.io.Serializable;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author KO
 */
@Data
@ApiModel(description = "CMS表栏目管理对象")
public class ColumnAppIconVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "栏目图标",example = "true")
    private String xappIconUrl;

}