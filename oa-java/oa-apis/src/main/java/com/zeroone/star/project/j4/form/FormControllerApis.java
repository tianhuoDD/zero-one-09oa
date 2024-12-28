package com.zeroone.star.project.j4.form;

import com.zeroone.star.project.dto.j4.form.data.FormInfoDTO;
import com.zeroone.star.project.dto.j4.form.data.FormListDTO;
import com.zeroone.star.project.dto.j4.form.manage.UpdateFormDTO;
import com.zeroone.star.project.dto.j4.form.data.CategoryDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.form.data.CategoryVO;
import com.zeroone.star.project.vo.j4.form.data.FormInfoVO;
import com.zeroone.star.project.vo.j4.form.data.FormListVO;
import com.zeroone.star.project.vo.j4.form.manage.UpdateFormVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

public interface FormControllerApis {

    /*
     * @description:获取表单信息
     * @author: quhutunlangconfig
     * @date: 2024/10/21 10:22
     * @param: [id]
     * @return: PpEForm
     **/
//    JsonVO<UpdateFormVO> getForm(String xid);

    /*
     * @description:更新表单信息
     * @author: quhutunlang
     * @date: 2024/10/21 10:22
     * @param: [ppEForm]
     * @return: 布尔结果
     **/
//    JsonVO<Boolean> updateForm(UpdateFormDTO ppEFormDTO);


    /**
     *@description:获取表单详情
     * @author: cheng
     * @param formInfoDTO
     * @return
     * @return: FormInfoVO
     */

    @ApiOperation("获取表单详情")
    @GetMapping("/query-form-info")
    JsonVO<FormInfoVO> queryFormInfo(FormInfoDTO formInfoDTO);

    /**
     *@description:获取表单列表
     * @author: cheng
     * @param formListDTO
     * @return: FormInfoVO
     */
    @ApiOperation("获取表单列表")
    @GetMapping("/query-form-list")
    JsonVO<List<FormListVO>> queryFormList(FormListDTO formListDTO);


    /**
     * @description:获取表单类型
     * @param categoryDTO
     * @return List<CategoryVO>
     */
    @ApiOperation("获取所有表单类型")
    @GetMapping("/query-form-category")
    JsonVO<List<CategoryVO>> queryCategoryVO( CategoryDTO categoryDTO);


}
