package com.zeroone.star.cmshome.service.impl;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.zeroone.star.cmshome.entity.PublishMessage;
import com.zeroone.star.cmshome.entity.QryItem;
import com.zeroone.star.cmshome.mapper.*;
import com.zeroone.star.cmshome.service.IPublishMessageService;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;

import static com.zeroone.star.cmshome.service.impl.SaveMessageServiceImpl.qryItemInsert;

@Mapper(componentModel = "spring")
interface PMPublishMessageMapper {

    /**
     *消息发布DTO转实体类
     * @param publishMessageDTO
     * @return
     */
    //@Mapping(target = "msgInstant",source = "newMessageDTO")
    @Mapping(target = "cmsDocument",source = "publishMessageDTO")
    //@Mapping(target = "qryItem",source = "publishMessageDTO")
   // @Mapping(target = "message",source = "newMessageDTO")
    PublishMessage sample2SampleDTO(PublishMessageDTO publishMessageDTO);
}

/**
 * 发布消息实现
 * @author 王星峰
 */
@Service
public class PublishMessageServiceImpl extends ServiceImpl<PublishMessageMapper, PublishMessage> implements IPublishMessageService {

    @Resource
    PMPublishMessageMapper pmPublishMessageMapper;
    @Resource
    private MsgInstantMapper msgInstantMapper;

    @Resource
    private CmsDocumentMapper cmsDocumentMapper;

    @Resource
    private QryItemMapper qryItemMapper;

    @Resource
    private MsgMessageMapper msgMessageMapper;



    @Override
    @Transactional
    public boolean save(PublishMessageDTO publishMessageDTO) {
        PublishMessage publishMessage = pmPublishMessageMapper.sample2SampleDTO(publishMessageDTO);
        //int insert1 =msgInstantMapper.insert(publishMessage.getMsgInstant());
        CmsDocument cmsDocument = publishMessage.getCmsDocument();
        cmsDocument.setXcreateTime(LocalDateTime.now());
        cmsDocument.setXmodifyTime(LocalDateTime.now());
        cmsDocument.setXupdateTime(LocalDateTime.now());
        cmsDocument.setXpublishTime(LocalDateTime.now());
        return qryItemInsert(publishMessageDTO, cmsDocument, cmsDocumentMapper, qryItemMapper);
    }
}



