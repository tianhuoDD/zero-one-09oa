package com.zeroone.star.bizcenter.service;

import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormDataVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormVO;


public interface ProcessTableDataService {

    /**
     * 通过work表的xid，获取表单数据
     * @param xid
     * @return
     */
    ProcessFormDataVO getProcessTableDataByXid(String xid);
}
