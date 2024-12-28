package com.zeroone.star.filemanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 文件附件实体类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("file_attachment2")
@ApiModel(description = "文件附件实体类")
public class FileAttachment2 implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "唯一标识符", required = true)
    private String xid;

    @ApiModelProperty(value = "创建时间", required = true)
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "序列号")
    private String xsequence;

    @ApiModelProperty(value = "更新时间")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分发因子")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "描述")
    private String xdescription;

    @ApiModelProperty(value = "文件扩展名")
    private String xextension;

    @ApiModelProperty(value = "文件版本")
    private Integer xfileVersion;

    @ApiModelProperty(value = "文件夹路径")
    private String xfolder;

    @ApiModelProperty(value = "最后更新人")
    private String xlastUpdatePerson;

    @ApiModelProperty(value = "最后更新时间")
    private LocalDateTime xlastUpdateTime;

    @ApiModelProperty(value = "文件长度")
    private Long xlength;

    @ApiModelProperty(value = "文件名")
    private String xname;

    @ApiModelProperty(value = "原始文件名")
    private String xoriginFile;

    @ApiModelProperty(value = "上传人")
    private String xperson;

    @ApiModelProperty(value = "状态")
    private String xstatus;

    @ApiModelProperty(value = "文件类型")
    private String xtype;

}
