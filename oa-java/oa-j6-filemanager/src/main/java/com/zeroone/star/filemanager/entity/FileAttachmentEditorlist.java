package com.zeroone.star.filemanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 文件附件编辑列表实体类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("file_attachment_editorlist")
@ApiModel(description = "文件附件编辑列表实体类")
public class FileAttachmentEditorlist implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "附件唯一标识符", required = true)
    private String attachmentXid;

    @ApiModelProperty(value = "编辑者列表")
    private String xeditorList;

    @ApiModelProperty(value = "排序列")
    private Integer xorderColumn;

}
