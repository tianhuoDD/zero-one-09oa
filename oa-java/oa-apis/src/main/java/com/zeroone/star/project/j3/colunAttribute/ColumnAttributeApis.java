package com.zeroone.star.project.j3.colunAttribute;


import com.zeroone.star.project.j3.ColumnAttribute.dto.ColumnAttributeDTO;
import com.zeroone.star.project.j3.ColumnAttribute.vo.ColumnAttributeVO;
import com.zeroone.star.project.j3.formattribute.dto.ColumnFormDTO;
import com.zeroone.star.project.j3.formattribute.vo.ColumnFormVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface ColumnAttributeApis {
    //添加栏目表单
    public JsonVO<ColumnFormVO> addColumnForm(ColumnFormDTO columnFormDTO);
    //删除栏目表单
    public JsonVO<Boolean> deleteColumnForm(String id);

    //修改栏目表单
    public JsonVO<ColumnFormVO> modifyColumnForm(ColumnFormDTO cmsFormDTO);

    //获取栏目表单详情
    public JsonVO<ColumnFormVO> queryColumnForm(String id);

    public JsonVO<List<ColumnFormVO>> queryColumnFormList(String id);



}
