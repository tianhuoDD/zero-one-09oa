package com.zeroone.star.project.j5.bizcenter;



import com.zeroone.star.project.query.j5.bizcenter.ProcessManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessRecordsVO;

import java.util.List;


/**
 * <p>
 * 描述：办公中心-添加流程接口
 * </p>
 * @author
 * @version 1.0.0
 */
public interface ProcessManagerApis {
    /**
     * 查询流程流转数据
     * @param dataQuery 查询条件
     * @return
     */
    JsonVO<ProcessRecordsVO> queryProcess(ProcessManagementQuery dataQuery);

    /**
     * 查询流程记录
     * @param dataQuery 查询条件
     * @return 记录数据
     */
    JsonVO<List<ProcessRecordsVO>> queryProcessRecords(ProcessManagementQuery dataQuery);
}
