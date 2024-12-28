package com.zeroone.star.project.dto.j6.file;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;

@Data
@ApiModel("文件夹对象1")
public class FolderDTO {
    /**
     * 目录id
     */
    @ApiModelProperty(value = "唯一标识", required = false)
    private String xid;
    /**
     * 目录创建时间
     */
    @ApiModelProperty(value = "目录创建时间", required = false)
    private Date xcrateTime;
    /**
     * 目录更新时间
     */
    @ApiModelProperty(value = "目录更新时间", required = false)
    private Date xupdateTime;
    /**
     * 目录创建时间 + 目录id
     */
    @ApiModelProperty(value = "目录创建时间 + 目录id", required = false)
    private String xsequence;
    /**
     * 目录名字
     */
    @ApiModelProperty(value = "目录名字", required = true)
    private String xname;
    /**
     * 目录创建人的名字
     */
    @ApiModelProperty(value = "目录创建人的名字", required = false)
    private String xperson;
    /**
     * 该目录的上级目录id
     */
    @ApiModelProperty(value = "该目录的上级目录id", required = false)
    private String xsuperior;
}

