package com.zeroone.star.procmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.procmanager.entity.PpEProcess;
import com.zeroone.star.project.dto.j4.process.ModifyProcessOrAddProcessDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.process.DeleteProcessVO;
import com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO;
import org.apache.ibatis.annotations.Mapper;


/**
 * <p>
 *  服务类
 * </p>
 *
 * @author awei qy
 * @since 2024-10-21
 */
public interface IProcessService extends IService<PpEProcess> {



    /*
        删除流程对象
    */
    DeleteProcessVO deleteProcess(String id);


    /*
        修改流程对象
   */
    ModifyProcessOrAddProcessVO modifyProcessOrAddProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO);

    /**
     * 新增流程
     *
     * @param modifyProcessOrAddProcessDTO
     * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO>
     * @author 夜寻
     * @create 2024/11/2
     **/

    JsonVO<ModifyProcessOrAddProcessVO> saveProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO);
}
