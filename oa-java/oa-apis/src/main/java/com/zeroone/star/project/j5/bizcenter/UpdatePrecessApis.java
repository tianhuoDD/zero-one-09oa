package com.zeroone.star.project.j5.bizcenter;

import com.zeroone.star.project.dto.j5.bizcenter.PrecessingDTO;
import com.zeroone.star.project.dto.j5.bizcenter.ReplaceDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RerouteDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.RecordVO;
import com.zeroone.star.project.vo.j5.bizcenter.ReplaceVO;
import com.zeroone.star.project.vo.j5.bizcenter.RerouteVO;
import com.zeroone.star.project.vo.j5.bizcenter.RetractVO;

import java.util.Map;

public interface UpdatePrecessApis {

    /**
     * 工作调度.
     * @param rerouteDTO 调度对象
     * @return
     */
    JsonVO<RerouteVO> 	V2Reroute(String id , RerouteDTO rerouteDTO);

    /**
     * 撤回工作.
     * @param id 流程id
     * @return
     */
    JsonVO<RetractVO> V2Retract(String id);

    /**
     * 重置处理人
     * @param id 流程 ID
     * @param  replaceDTO 处理人标识集合
     * @return
     */
    JsonVO<ReplaceVO> 	ResetWorkPerson(String id, ReplaceDTO replaceDTO);


    /**
     * 删除文件
     * @param id 流程 ID
     * @return
     */
    JsonVO<String> DeleteWork(String id);


    /**
     * 	完成工作关闭时候的检查,1.检查是否要删除处于草稿状态的工作,没有保存过任何数据将被认为是草稿.2.检查是否需要释放抢办.
     * @param id
     * @return
     */
    JsonVO<Boolean> closeCheck(String id);

    /**
     * 	根据工作标识更新业务数据.
     * @param params
     * @return
     */
    JsonVO<String> updateWithWork(String id,Map<String, Object> params);


    /**
     * 继续流转
     * @param id
     * @param precessingDTO
     * @return
     */
    JsonVO<RecordVO> processing(String id, PrecessingDTO precessingDTO);



}
