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
@TableName("file_attachment")
public class FileAttachment implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识")
    @TableId(value = "xid")
    private String xid;

    /**
     * 文件夹创建时间
     */
    @ApiModelProperty(value = "文件夹创建时间")
    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    /**
     * 附件的顺序
     */
    @ApiModelProperty(value = "附件的顺序")
    @TableField("xsequence")
    private String xsequence;

    /**
     * 更新的时间
     */
    @ApiModelProperty(value = "更新的时间")
    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    /**
     * 分发因子（用于控制分发的策略）
     */
    @ApiModelProperty(value = "分发因子（用于控制分发的策略）")
    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    /**
     * 加密秘钥
     */
    @ApiModelProperty(value = "加密秘钥")
    @TableField("xencryptKey")
    private String xencryptKey;


    /**
     * 深层路径表示
     */
    @ApiModelProperty(value = "深层路径表示")
    @TableField("xdeepPath")
    private Boolean xdeepPath;

    /**
     * 文件扩展名
     */
    @ApiModelProperty(value = "文件扩展名")
    @TableField("xextension")
    private String xextension;

    /**
     * 附件所在文件夹
     */
    @ApiModelProperty(value = "附件所在文件夹")
    @TableField("xfolder")
    private String xfolder;

    /**
     * 最后更新附件的人员
     */
    @ApiModelProperty(value = "最后更新附件的人员")
    @TableField("xlastUpdatePerson")
    private String xlastUpdatePerson;

    /**
     * 最后更新的时间
     */
    @ApiModelProperty(value = "最后更新的时间")
    @TableField("xlastUpdateTime")
    private LocalDateTime xlastUpdateTime;

    /**
     * 附件的大小
     */
    @ApiModelProperty(value = "附件的大小")
    @TableField("xlength")
    private Long xlength;

    /**
     * 附件的名称
     */
    @ApiModelProperty(value = "附件的名称")
    @TableField("xname")
    private String xname;
    /**
     * 上传附件的人员
     */
    @ApiModelProperty(value = "上传附件的人员")
    @TableField("xperson")
    private String xperson;

    /**
     * 存储位置
     */
    @ApiModelProperty(value = "存储位置")
    @TableField("xstorage")
    private String xstorage;


}
