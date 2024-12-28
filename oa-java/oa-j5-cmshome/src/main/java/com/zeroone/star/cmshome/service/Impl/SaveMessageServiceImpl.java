package com.zeroone.star.cmshome.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.zeroone.star.cmshome.entity.PublishMessage;
import com.zeroone.star.cmshome.entity.QryItem;
import com.zeroone.star.cmshome.mapper.*;
import com.zeroone.star.cmshome.service.ISaveMessageService;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;
import org.mapstruct.Mapper;

import org.mapstruct.Mapping;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

@Mapper(componentModel = "spring")
interface SMSaveMessageMapper {

    /**
     *消息发布DTO转实体类
     * @param publishMessageDTO
     * @return
     */
    @Mapping(target = "cmsDocument",source = "publishMessageDTO")
   PublishMessage sample2SampleDTO(PublishMessageDTO publishMessageDTO);
}

/**
 * 保存草稿
 * @author wxf
 */
@Service
public class SaveMessageServiceImpl extends ServiceImpl<QryItemMapper, QryItem> implements ISaveMessageService {

    @Resource
    SMSaveMessageMapper smSaveMessageMapper;
    @Resource
    private CmsDocumentMapper cmsDocumentMapper;

    @Resource
    private QryItemMapper qryItemMapper;





    @Override
    @Transactional
    public boolean save(PublishMessageDTO publishMessageDTO) {
        PublishMessage publishMessage = smSaveMessageMapper.sample2SampleDTO(publishMessageDTO);
        CmsDocument cmsDocument = publishMessage.getCmsDocument();
        cmsDocument.setXcreateTime(LocalDateTime.now());
        cmsDocument.setXmodifyTime(LocalDateTime.now());
        cmsDocument.setXupdateTime(LocalDateTime.now());
        cmsDocument.setXdocStatus("draft");
        return qryItemInsert(publishMessageDTO, cmsDocument, cmsDocumentMapper, qryItemMapper);
    }

    static boolean qryItemInsert(PublishMessageDTO publishMessageDTO, CmsDocument cmsDocument, CmsDocumentMapper cmsDocumentMapper, QryItemMapper qryItemMapper) {
        int insert = cmsDocumentMapper.insert(cmsDocument);
        QryItem qryItem = new QryItem();
        qryItem.setXcreateTime(LocalDateTime.now());
        qryItem.setXupdateTime(LocalDateTime.now());
        qryItem.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + qryItem.getXid());
        qryItem.setXitemCategory("cms");
        qryItem.setXpath0("explain");
        qryItem.setXstringShortValue(publishMessageDTO.getXdocData().getExplain());
        qryItemMapper.insert(qryItem);
        QryItem qryItem1 = new QryItem();
        qryItem.setXcreateTime(LocalDateTime.now());
        qryItem.setXupdateTime(LocalDateTime.now());
        qryItem.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + qryItem1.getXid());
        qryItem.setXitemCategory("cms");
        qryItem.setXpath0("htmleditor");
        qryItem.setXstringShortValue(publishMessageDTO.getXdocData().getHtmleditor());
        qryItemMapper.insert(qryItem1);

        if (insert > 0 ){
            return true;
        }else {
            return false;
        }
    }
}



