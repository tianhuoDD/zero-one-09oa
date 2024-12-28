package com.zeroone.star.procmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.procmanager.entity.PpEForm;
import com.zeroone.star.project.dto.j4.form.manage.UpdateFormDTO;

public interface IFormManageService extends IService<PpEForm> {

    /**
     * @description:获取表单内容，用于测试
     * @author: quhutunlang
     * @date: 2024/10/25 9:15
     * @param: [xid]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.form.manage.UpdateFormVO>
     **/
    UpdateFormDTO getForm(String xid);


    /**
     * @description:新建表单
     * @author: quhutunlang
     * @date: 2024/10/25 9:16
     * @param: [updateFormDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.form.manage.AddFormVO>
     **/
    Boolean addForm(UpdateFormDTO updateFormDTO);

    /**
     * @description:更新表单内容
     * @author: quhutunlang
     * @date: 2024/10/25 9:16
     * @param: [updateFormDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.form.manage.UpdateFormVO>
     **/
    Boolean updateForm(UpdateFormDTO updateFormDTO);

    /**
     * @description:删除表单
     * @author: quhutunlang
     * @date: 2024/10/25 9:36
     * @param: [xids]
     * @return: java.lang.Boolean
     **/
    Boolean deleteForm(String[] xids);
}
