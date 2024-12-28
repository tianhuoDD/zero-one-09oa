package com.zeroone.star.project.query.j6.file;

import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;
import java.time.LocalDateTime;
@Data
@ApiModel("文件夹分页查询")
@TableName("file_folder")
public class FolderQuery extends PageQuery {
    /**
     * 需要查看的目录的唯一标识
     */
    @ApiModelProperty(value = "需要查看的目录的一标识", required = false)
    private String xid;
    /**
     *目录创建时间
     */
    @ApiModelProperty(value = "目录创建时间", required = false)
    private Date xcrateTime;
    /**
     *目录更新时间
     */
    @ApiModelProperty(value = "目录更新时间", required = false)
    private Date xupdateTime;
    /**
     *目录名字
     */
    @ApiModelProperty(value = "目录名字", required = false)
    private String xname;
    /**
     *目录创建人的名字
     */
    @ApiModelProperty(value = "目录创建人的名字", required = false)
    private String xperson;
    /**
     *目录下的文件数
     */
    @ApiModelProperty(value = "目录下的文件数", required = false)
    private Integer xfilesNum;
    /**
     *目录的所占内存大小
     */
    @ApiModelProperty(value = "目录的所占内存大小", required = false)
    private Integer xlength;


}
