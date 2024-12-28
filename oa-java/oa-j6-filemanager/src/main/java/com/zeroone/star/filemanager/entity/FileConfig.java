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
 * 文件配置实体类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("file_config")
@ApiModel(description = "文件配置实体类")
public class FileConfig implements Serializable {

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

    @ApiModelProperty(value = "容量")
    private Integer xcapacity;

    @ApiModelProperty(value = "名称")
    private String xname;

    @ApiModelProperty(value = "负责人")
    private String xperson;

    @ApiModelProperty(value = "属性")
    private String xproperties;

    @ApiModelProperty(value = "回收天数")
    private Integer xrecycleDays;

}
