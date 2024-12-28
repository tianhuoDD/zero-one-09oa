package com.zeroone.star.project.j4.form;

import com.zeroone.star.project.dto.j4.form.manage.UpdateFormDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.form.manage.UpdateFormVO;
import io.swagger.annotations.ApiOperation;

public interface FormManageApis {

    /**
     * @description:获取表单信息
     * @author: quhutunlangconfig
     * @date: 2024/10/21 10:22
     * @param: [id]
     * @return: PpEForm
     **/
//    JsonVO<UpdateFormVO> getForm(String xid);

    /**
     * @description:新增表单
     * @author: quhutunlang
     * @date: 2024/10/25 9:04
     * @param: [updateFormDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.form.manage.AddFormVO>
     **/
    @ApiOperation("新增表单")
    JsonVO<Boolean> addForm(UpdateFormDTO updateFormDTO);

    /**
     * @description:更新表单信息
     * @author: quhutunlang
     * @date: 2024/10/21 10:22
     * @param: [ppEForm]
     * @return: 布尔结果
     **/
    JsonVO<Boolean> updateForm(UpdateFormDTO ppEFormDTO);

    /**
     * @description:删除表单
     * @author: quhutunlang
     * @date: 2024/10/25 9:04
     * @param: [xid]
     * @return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     **/
    @ApiOperation("删除表单")
    JsonVO<Boolean> deleteForm(String[] xids);
}
