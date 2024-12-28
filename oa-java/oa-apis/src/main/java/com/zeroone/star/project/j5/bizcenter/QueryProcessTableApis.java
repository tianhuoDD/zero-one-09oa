package com.zeroone.star.project.j5.bizcenter;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormDataVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormVO;

/**
 * 流程的接口
 */
public interface QueryProcessTableApis {

    /**
     * 通过表单格式xid获取表格
     * @param xid
     * @return
     */
    JsonVO<ProcessFormVO> queryProcessTable(String xid);

}
