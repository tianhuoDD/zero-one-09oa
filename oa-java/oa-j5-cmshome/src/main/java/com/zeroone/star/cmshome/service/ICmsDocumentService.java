package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.CmsDocument;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 */
public interface ICmsDocumentService extends IService<CmsDocument> {

    /*
    * 上传新建的消息页面
     */
    boolean addNewMessage(NewMessageDTO newMessageDTO);

    /*
    * 根据documentId查询document
    */
    CmsDocument queryDocument(String xid);

    /*
    * 更新document
     */
    boolean updateDocument(CmsDocument cmsDocument);
}
