package com.zeroone.star.filemanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 *
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Data
@TableName("file_folder")
public class FileFolder implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 目录id
     */
    @ApiModelProperty(value = "目录id", required = false)
    @TableId(value = "xid")
    private String xid;

    /**
     * 目录创建时间
     */
    @ApiModelProperty(value = "目录创建时间", required = false)
    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    /**
     * 目录更新时间
     */
    @ApiModelProperty(value = "目录更新时间", required = false)
    @TableField("xsequence")
    private String xsequence;

    /**
     * 目录创建时间 + 目录id
     */
    @ApiModelProperty(value = "目录创建时间 + 目录id", required = false)
    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;


    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    /**
     * 目录名字
     */
    @ApiModelProperty(value = "目录名字", required = true)
    @TableField("xname")
    private String xname;

    /**
     * 目录创建人的名字
     */
    @ApiModelProperty(value = "目录创建人的名字", required = false)
    @TableField("xperson")
    private String xperson;

    /**
     * 该目录的上级目录id
     */
    @ApiModelProperty(value = "该目录的上级目录id", required = false)
    @TableField("xsuperior")
    private String xsuperior;


}
