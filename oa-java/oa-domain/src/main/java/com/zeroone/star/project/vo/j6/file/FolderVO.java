package com.zeroone.star.project.vo.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;

@Data
@ApiModel("文件夹显示")
public class FolderVO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识")
    private String xid;
    /**
     *目录创建时间
     */
    @ApiModelProperty(value = "目录创建时间")
    private Date xcrateTime;
    /**
     *目录更新时间
     */
    @ApiModelProperty(value = "目录更新时间")
    private Date xupdateTime;
    /**
     *目录名字
     */
    @ApiModelProperty(value = "目录名字")
    private String xname;
    /**
     *目录创建人的名字
     */
    @ApiModelProperty(value = "目录创建人的名字")
    private String xperson;
    /**
     *目录下的文件数
     */
    @ApiModelProperty(value = "目录下的文件数")
    private Integer xfilesNum;
    /**
     *目录的所占内存大小
     */
    @ApiModelProperty(value = "目录的所占内存大小")
    private Integer xlength;
}
