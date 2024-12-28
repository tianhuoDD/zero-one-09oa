package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 
 * </p>
 *
 * @author han
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("file_attachment_sharelist")
public class FileAttachmentSharelist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String attachmentXid;

    private String xshareList;

    private Integer xorderColumn;


}
