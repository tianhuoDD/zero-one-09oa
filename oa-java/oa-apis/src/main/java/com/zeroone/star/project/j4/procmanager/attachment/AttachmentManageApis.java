package com.zeroone.star.project.j4.procmanager.attachment;

import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * 附件管理相关接口
 *
 * @author 夜寻
 * @create 2024/10/20
 **/
public interface AttachmentManageApis {

    /**
     * 新增附件
     *
     * @param multipartFile
     * @param attachmentId
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     * @author 夜寻
     * @create 2024/10/20
     **/
    JsonVO<String> addAttachment(String applicationId,MultipartFile multipartFile,String attachmentId);

    /**
     * 修改附件
     *
     * @param attachmentInfoDTO
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     * @author 夜寻
     * @create 2024/10/20
     **/

    JsonVO<String> modifyAttachment(AttachmentDTO attachmentInfoDTO);
    /**
     * 删除附件
     *
     * @param xids
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     * @author 夜寻
     * @create 2024/10/20
     **/

    JsonVO<String> removeAttachment(String xids);
}
