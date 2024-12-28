package com.zeroone.star.procmanager.service;

import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

public interface AttachmentManagerService {
    /**
     * 新增附件
     *
     * @param file
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @author 夜寻
     * @create 2024/10/21
     **/

    public JsonVO<String> saveAttachment(String applicationId,MultipartFile file,String attachmentId);
    /**
     * 修改附件
     *
     * @param attachmentDTO
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @author 夜寻
     * @create 2024/10/21
     **/

    public JsonVO<String> updateAttachment(AttachmentDTO attachmentDTO);

    /**
     * 删除附件
     *
     * @param xids
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @author 夜寻
     * @create 2024/10/21
     **/
    public JsonVO<String> removeAttachment(String xids);
}
