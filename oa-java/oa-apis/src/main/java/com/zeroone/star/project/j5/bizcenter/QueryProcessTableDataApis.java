package com.zeroone.star.project.j5.bizcenter;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormDataVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormVO;

/**
 * 流程的接口
 */
public interface QueryProcessTableDataApis {

    /**
     * 通过work表的xid 查询流程表格数据
     * @param xid
     * @return
     */
    JsonVO<ProcessFormDataVO> queryProcessTableData(String xid);
}
