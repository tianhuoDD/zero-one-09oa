package com.zeroone.star.project.j4.process;


import com.zeroone.star.project.dto.j4.process.DeleteProcessDTO;
import com.zeroone.star.project.dto.j4.process.ModifyProcessOrAddProcessDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.process.DeleteProcessVO;
import com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO;
import org.springframework.web.bind.annotation.RequestParam;

public interface ProcessApis {
    /**
     * 新增流程
     *
     * @param modifyProcessOrAddProcessDTO
     * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO>
     * @author 夜寻
     * @create 2024/11/2
     **/

    JsonVO<ModifyProcessOrAddProcessVO> addProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO);


    /*
        删除流程对象
    */
    JsonVO<DeleteProcessVO> deleteProcess(@RequestParam(value = "id") String id);


    /*
        修改流程对象
   */
    JsonVO<ModifyProcessOrAddProcessVO> modifyProcessOrAddProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO);
}
