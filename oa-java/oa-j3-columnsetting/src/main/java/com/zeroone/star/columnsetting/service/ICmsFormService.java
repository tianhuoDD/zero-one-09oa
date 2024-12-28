package com.zeroone.star.columnsetting.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.columnsetting.entity.CmsForm;
import com.zeroone.star.project.j3.formattribute.dto.ColumnFormDTO;
import com.zeroone.star.project.j3.formattribute.vo.ColumnFormVO;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 *  栏目表单接口类
 * </p>
 *
 * @author lenyan
 * @since 2024-10-19
 */
public interface ICmsFormService extends IService<CmsForm> {
    /**
     * 添加栏目表单
     * @param columnFormDTO
     * @return
     */
    JsonVO<ColumnFormVO> addColumnForm(ColumnFormDTO columnFormDTO);

    /**
     * 根据id删除栏目表单
     * @param id
     * @return
     */
    JsonVO<Boolean> deleteColumnForm(String id);

    JsonVO<ColumnFormVO> modifyColumnForm(@Valid ColumnFormDTO cmsFormDTO);

    JsonVO<ColumnFormVO> queryColumnForm(String id);

    JsonVO<List<ColumnFormVO>> queryColumnFormList(String id);
}
