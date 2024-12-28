package com.zeroone.star.project.vo.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 文件夹信息显示对象
 */
@Data
@ApiModel("文件夹显示对象")
public class FileAttachmentVO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识")
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
     * 加密秘钥
     */
    @ApiModelProperty(value = "加密秘钥")
    private String xencryptKey;
    /**
     * 深层路径表示
     */
    @ApiModelProperty(value = "深层路径表示")
    private Boolean xdeepPath;
    /**
     * 文件扩展名
     */
    @ApiModelProperty(value = "文件扩展名")
    private String xextension;
    /**
     * 附件所在文件夹
     */
    @ApiModelProperty(value = "附件所在文件夹")
    private String xfolder;
    /**
     * 最后更新附件的人员
     */
    @ApiModelProperty(value = "最后更新附件的人员")
    private String xlastUpdatePerson;
    /**
     * 最后更新的时间
     */
    @ApiModelProperty(value = "最后更新的时间")
    private LocalDateTime xlastUpdateTime;
    /**
     * 附件的大小
     */
    @ApiModelProperty(value = "附件的大小")
    private Long xlength;
    /**
     * 附件的名称
     */
    @ApiModelProperty(value = "附件的名称")
    private String xname;
    /**
     * 上传附件的人员
     */
    @ApiModelProperty(value = "上传附件的人员")
    private String xperson;
    /**
     * 存储位置
     */
    @ApiModelProperty(value = "存储位置")
    private String xstorage;
}
