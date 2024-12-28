package com.zeroone.star.cmshome.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.cmshome.entity.CmsForm;
import com.zeroone.star.cmshome.mapper.CmsFormMapper;
import com.zeroone.star.cmshome.service.ICmsFormService;
import com.zeroone.star.project.dto.j5.cmshome.DocumentDTO;
import com.zeroone.star.project.vo.j5.cmshome.form.DocumentFormDataVO;
import com.zeroone.star.project.vo.j5.cmshome.form.DocumentFormVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.HashMap;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 * @author huangfeifan
 * @since 2024-10-29
 */
@Service
public class CmsFormServiceImpl extends ServiceImpl<CmsFormMapper, CmsForm> implements ICmsFormService {

    @Resource
    private CmsFormMapper cmsFormMapper;

    @Override
    public CmsForm queryForm(String xid) {
        return baseMapper.selectById(xid);
    }

    @Override
    public boolean updateForm(CmsForm cmsForm) {
        int result = baseMapper.updateById(cmsForm);
        if (result != 0) {
            return true;
        }
        return false;
    }

    @Override
    public DocumentFormVO getDocumentFormById(String xid) {
        CmsForm cmsForm = cmsFormMapper.selectById(xid);
        DocumentFormVO documentFormVO = new DocumentFormVO();
        documentFormVO.setXdata(cmsForm.getXdata());
        return documentFormVO;
    }

    @Override
    public DocumentDTO getDocumentFormData(String xid) {
        CmsForm cmsForm = cmsFormMapper.selectById(xid);
        DocumentFormVO documentFormVO = new DocumentFormVO();
        documentFormVO.setXdata(cmsForm.getXdata());

        DocumentFormDataVO documentFormDataVO = new DocumentFormDataVO();
        documentFormDataVO.setXid(xid);
        documentFormDataVO.setData(documentFormVO);
        documentFormDataVO.setXalias(cmsForm.getXalias());
        documentFormDataVO.setXname(cmsForm.getXname());
        documentFormDataVO.setXappId(cmsForm.getXappId());

        DocumentDTO documentDTO = new DocumentDTO();
        documentDTO.setForm(documentFormDataVO);
        documentDTO.setMaxAge(86400);
        documentDTO.setRelatedFormMap(new HashMap<>());
        documentDTO.setRelatedScriptMap(new HashMap<>());
        documentDTO.setFastETag("");
        return documentDTO;
    }
}
