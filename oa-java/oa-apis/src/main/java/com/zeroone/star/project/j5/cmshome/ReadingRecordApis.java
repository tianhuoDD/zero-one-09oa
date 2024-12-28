package com.zeroone.star.project.j5.cmshome;

/**
 * 阅读记录相关接口
 */

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetReadingRecordVO;
import com.zeroone.star.project.vo.j5.cmshome.UpdateReadingRecordVO;


public interface ReadingRecordApis {
    /**
     * 获取阅读记录
     * @param xid 要查询的阅读记录ID
     * @return 获取到的信息
     */
    JsonVO<GetReadingRecordVO> getReadingRecord(String xid);


    /**
     * 更新阅读记录
     * @param xid 要更新的阅读记录id
     * @return 更新后的阅读记录
     */
    JsonVO<UpdateReadingRecordVO> updateReadingRecord(String xid);


}


