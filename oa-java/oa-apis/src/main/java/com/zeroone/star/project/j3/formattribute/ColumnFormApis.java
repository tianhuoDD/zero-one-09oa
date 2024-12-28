package com.zeroone.star.project.j3.formattribute;

import com.zeroone.star.project.j3.formattribute.dto.ColumnFormDTO;
import com.zeroone.star.project.j3.formattribute.vo.ColumnFormVO;
import com.zeroone.star.project.vo.JsonVO;
import java.util.List;

/**
 * @Program: zero-one-09oa   //名称
 * @ClassName : ColumnFormApis  //类名
 * @Author: lenyan   /作者
 * @Date: 2024/10/15  23:42
 **/

public interface ColumnFormApis {

    public JsonVO<ColumnFormVO> addColumnForm(ColumnFormDTO cmsFormDTO);

    public JsonVO<Boolean> deleteColumnForm(String id);

    //修改栏目表单
    public JsonVO<ColumnFormVO> updateColumnForm(ColumnFormDTO cmsFormDTO);

    //获取栏目表单详情
    public JsonVO<ColumnFormVO> queryColumnForm(String id);

    //TODO 获取栏目表单列表,请求参数
    public JsonVO<List<ColumnFormDTO>> queryColumnFormList(String id);


}
