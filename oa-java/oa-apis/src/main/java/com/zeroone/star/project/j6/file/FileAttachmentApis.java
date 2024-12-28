package com.zeroone.star.project.j6.file;

import com.zeroone.star.project.vo.JsonVO;

/**
 * 文件操作相关接口声明
 */
public interface FileAttachmentApis {

    JsonVO<Integer> modifyFileAttachmentName(String xid,String new_name,String xfolder,String xlastUpdatePerson);

    JsonVO<Integer> removeFileAttachment(String xid);
}
