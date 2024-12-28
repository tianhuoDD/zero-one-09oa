package com.zeroone.star.project.vo.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * 文件夹信息显示对象 Folder + Attachment
 */
@Data
@ApiModel("文件夹信息显示对象（文件夹 + 文件）")
public class FileContentVO {
    /**
     * 文件夹列表
     */
    @ApiModelProperty(value = "文件夹列表")
    List<FileFolderVO> fileFolders;
    /**
     * 文件列表
     */
    @ApiModelProperty(value = "文件列表")
    List<FileAttachmentVO> fileAttachments;
}
