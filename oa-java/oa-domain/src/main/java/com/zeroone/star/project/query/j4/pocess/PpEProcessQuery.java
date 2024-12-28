package com.zeroone.star.project.query.j4.pocess;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("流程查询对象")
public class PpEProcessQuery extends PageQuery {

    @ApiModelProperty(value = "标识", example = "123456")
    private String xid;

    @NotBlank(message = "未实现")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间", example = "2024-10-24 16:35:07")
    private LocalDateTime xcreateTime;

    @NotBlank(message = "未实现")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "更新时间", example = "2024-10-24 22:38:09")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "别名", example = "流程")
    private String xalias;

    @ApiModelProperty(value = "应用", example = "应用1")
    private String xapplication;

    @ApiModelProperty(value = "分类", example = "类别1")
    private String xcategory;

    @ApiModelProperty(value = "创建人", example = "戴夫")
    private String xcreatorPerson;

    @ApiModelProperty(value = "名称", example = "666")
    private String xname;

}
