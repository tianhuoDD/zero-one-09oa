package com.zeroone.star.project.dto.j5.cmshome;

import com.zeroone.star.project.vo.j5.cmshome.form.DocumentFormDataVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Map;

@Data
@ApiModel("消息详情")
public class DocumentDTO {
    @ApiModelProperty("消息表单")
    private DocumentFormDataVO form;
    @ApiModelProperty(value = "表单关联表")
    private Map<String, String> relatedFormMap;
    @ApiModelProperty(value = "表单关联脚本")
    private Map<String, String> relatedScriptMap;
    @ApiModelProperty(value = "快实体标签")
    private String fastETag;
    @ApiModelProperty(value = "最大存在时间",example = "86400")
    private Integer maxAge;
}
