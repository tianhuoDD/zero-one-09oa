package com.zeroone.star.filemanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 文件附件分享列表实体类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Getter
@Setter
@NoArgsConstructor
@TableName("file_attachment_sharelist")
@ApiModel(description = "文件附件分享列表实体类")
public class FileAttachmentSharelist implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "附件唯一标识符", required = true)
    private String attachmentXid;

    @ApiModelProperty(value = "分享者列表")
    private String xshareList;

    @ApiModelProperty(value = "排序列")
    private Integer xorderColumn;

}
