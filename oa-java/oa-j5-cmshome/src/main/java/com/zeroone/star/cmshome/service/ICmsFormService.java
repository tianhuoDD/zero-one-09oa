package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.CmsForm;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.cmshome.DocumentDTO;
import com.zeroone.star.project.vo.j5.cmshome.form.DocumentFormVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 * @author huangfeifan
 * @since 2024-10-29
 */
public interface ICmsFormService extends IService<CmsForm> {

    /*
    * 根据id查询form模板
    */
    CmsForm queryForm(String xid);

    /*
    * 更新form模板
    */
    boolean updateForm(CmsForm cmsForm);


    DocumentFormVO getDocumentFormById(String xid);

    DocumentDTO getDocumentFormData(String xid);
}
