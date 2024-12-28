package com.zeroone.star.bizcenter.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.bizcenter.entity.PPEFrom;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFromVO;
import org.springframework.beans.factory.annotation.Autowired;


public interface IPpEFromService extends IService<PPEFrom> {



    /**
     * 根据id查询流程表单信息
     * @param id
     * @return
     */
    ProcessFromVO getFromById(String id);


    /**
     * 根据流程id查询 pp_e_from表
     */
    PPEFrom getPpeFromById(String id);

}
