package com.zeroone.star.project.dto.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


@Data
@ApiModel("文件夹对象1")
public class FileFolderDTO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识",required = true,example = "eba32d1cd260")
    private String xid;
    /**
     * 文件夹创建时间
     */
    @ApiModelProperty(value = "文件夹创建时间")
    private LocalDateTime xcreateTime;
    /**
     * 附件的顺序
     */
    @ApiModelProperty(value = "附件的顺序")
    private String xsequence;
    /**
     * 更新的时间
     */
    @ApiModelProperty(value = "更新的时间")
    private LocalDateTime xupdateTime;
    /**
     * 分发因子（用于控制分发的策略）
     */
    @ApiModelProperty(value = "分发因子（用于控制分发的策略）")
    private Integer xdistributeFactor;
    /**
     * 文件夹名称
     */
    @ApiModelProperty(value = "文件夹名称",required = true)
    private String xname;
    /**
     * 创建文件夹的人员
     */
    @ApiModelProperty(value = "创建文件夹的人员")
    private String xperson;
    /**
     * 上级文件夹
     */
    @ApiModelProperty(value = "上级文件夹",example = "eba32d1cd259")
    private String xsuperior;
}
