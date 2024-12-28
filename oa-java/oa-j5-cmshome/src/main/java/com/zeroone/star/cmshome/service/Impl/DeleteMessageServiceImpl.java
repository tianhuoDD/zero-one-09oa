package com.zeroone.star.cmshome.service.impl;


import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.zeroone.star.cmshome.entity.PublishMessage;
import com.zeroone.star.cmshome.entity.QryItem;
import com.zeroone.star.cmshome.mapper.CmsDocumentMapper;
import com.zeroone.star.cmshome.mapper.PublishMessageMapper;
import com.zeroone.star.cmshome.mapper.QryItemMapper;
import com.zeroone.star.cmshome.service.IDeleteMessageService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * 删除消息
 * @author wxf
 */
@Service
public class DeleteMessageServiceImpl extends ServiceImpl<QryItemMapper, QryItem> implements IDeleteMessageService {


    @Resource
    private CmsDocumentMapper cmsDocumentMapper;

    @Resource
    private QryItemMapper qryItemMapper;

    @Override
    @Transactional
    public boolean delete(List<String> ids) {
        if (ids == null || ids.isEmpty()) {
            return false; // 如果 ID 列表为空，直接返回
        }
        // 使用 QueryWrapper 删除
        List<CmsDocument> cmsDocuments = cmsDocumentMapper.selectBatchIds(ids);
        List<String> xids = cmsDocuments.stream()
                .map(CmsDocument::getXid)
                .collect(Collectors.toList());
        QueryWrapper<QryItem> queryWrapper = new QueryWrapper<>();
        queryWrapper.in("xbundle", xids);
        qryItemMapper.delete(queryWrapper);
        int delete = cmsDocumentMapper.delete(new QueryWrapper<CmsDocument>().in("xid", ids));

        if (delete > 0 ){
            return true;
        }else {
            return false;
        }

    }
}



