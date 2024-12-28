package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.dto.j5.cmshome.DocumentDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.form.DocumentFormVO;

/**
 * 描述
 *
 * @author Henry
 */
public interface DocumentFormApis {
    /**
     * 获取表单模板
     *
     * @param xid 表单唯一标识
     * @return 获取到的表单模板
     */
    JsonVO<DocumentFormVO> queryById(String xid);

    /**
     * 获取消息表单数据
     * @param xid   消息表单数据唯一标识
     * @return  获取到的消息数据
     */
    JsonVO<DocumentDTO> queryFormData(String xid);
}
