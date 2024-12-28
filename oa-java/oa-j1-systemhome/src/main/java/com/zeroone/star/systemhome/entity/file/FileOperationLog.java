package com.zeroone.star.systemhome.entity.file;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author 李云毅
 * @since 2024-10-26
 */
@Getter
@Setter
@TableName("file_operation_log")
public class FileOperationLog implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    private String xid;

    /**
     * 1-发送，2-分享，3-删除，4-上传
     */
    private Integer xOperationType;

    /**
     * 发起者
     */
    private String xFromPerson;

    /**
     * 接收者
     */
    private String xToPerson;

    /**
     * 操作时间
     */
    private LocalDateTime xOperationTime;

    /**
     * 操作文件的唯一标识
     */
    private String fileAttachmentId;


}
