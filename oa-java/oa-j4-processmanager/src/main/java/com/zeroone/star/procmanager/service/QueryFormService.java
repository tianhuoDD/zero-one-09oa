package com.zeroone.star.procmanager.service;


import com.zeroone.star.project.dto.j4.form.data.CategoryDTO;
import com.zeroone.star.project.dto.j4.form.data.FormInfoDTO;
import com.zeroone.star.project.dto.j4.form.data.FormListDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.form.data.CategoryVO;
import com.zeroone.star.project.vo.j4.form.data.FormInfoVO;
import com.zeroone.star.project.vo.j4.form.data.FormListVO;

import java.util.List;

public interface QueryFormService {

    /**
     * 查询所有类型
     * @param categoryDTO
     * @return
     */
    JsonVO<List<CategoryVO>> queryCategoryVO(CategoryDTO categoryDTO);

    /**
     * 查询表单列表
     * @param formListDTO
     * @return
     */
    List<FormListVO> queryFormList(FormListDTO formListDTO);

    FormInfoVO queryFormInfo(FormInfoDTO formInfoDTO);
}
