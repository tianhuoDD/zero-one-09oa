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
 * 回收站文件实体类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("file_recycle")
@ApiModel(description = "回收站文件实体类")
public class FileRecycle implements Serializable {

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

    @ApiModelProperty(value = "文件扩展名")
    private String xextension;

    @ApiModelProperty(value = "文件ID", required = true)
    private String xfileId;

    @ApiModelProperty(value = "文件类型")
    private String xfileType;

    @ApiModelProperty(value = "文件长度")
    private Long xlength;

    @ApiModelProperty(value = "文件名")
    private String xname;

    @ApiModelProperty(value = "负责人")
    private String xperson;

    @ApiModelProperty(value = "有效时间")
    private LocalDateTime xvalidTime;

}
