package com.zeroone.star.bizcenter.service;

import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormDataVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormVO;


public interface ProcessTableService {

    /**
     * 通过表单格式id，获取表单格式
     * @param xid
     * @return
     */
    ProcessFormVO getProcessTableByXid(String xid);


}
