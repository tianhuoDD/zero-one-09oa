package com.zeroone.star.project.j3.ColumnAttribute.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.List;

/**
 * CMS表单数据传输对象
 *
 * 该类表示CMS系统中的表单信息的数据传输对象。
 *
 * @author lenyan
 * @since 2024-10-15
 */
@Data
@ApiModel(description = "CMS表栏目属性对象")
public class ColumnAttributeDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "栏目标识",example = "1")
    private String xid;

    @ApiModelProperty(value = "栏目名称",example = "名字")
    private String xappName;

    @ApiModelProperty(value = "栏目别名",example = "别名")
    private String xappAlias;

    @ApiModelProperty(value = "栏目类型",example = "栏目类型")
    private String xappType;

    @ApiModelProperty(value = "文档类型",example = "文档类型")
    private String xdocumentType;

    @ApiModelProperty(value = "栏目描述",example = "描述")
    private String xdescription;

    @ApiModelProperty(value = "栏目排列",example = "1")
    private String xsequence;

    @ApiModelProperty(value = "忽略标题",example = "true")
    private Boolean ignoreTitle;

    @ApiModelProperty(value = "检查草稿",example = "true")
    private Boolean latest;

    @ApiModelProperty(value = "栏目视图",example = "true")
    private Boolean xshowAllDocuments;

    @ApiModelProperty(value = "自动保存",example = "true")
    private Boolean saveDraftOnClose;

    @ApiModelProperty(value = "默认编辑表单",example = "表单一")
    private String xdefaultEditForm;

    @ApiModelProperty(value = "默认阅读表单",example = "表单二")
    private String xdefaultReadForm;



}