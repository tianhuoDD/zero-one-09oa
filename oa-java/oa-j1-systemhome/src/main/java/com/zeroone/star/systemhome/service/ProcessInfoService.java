package com.zeroone.star.systemhome.service;

import com.zeroone.star.project.vo.j1.system.home.ProcessInfoVo;

import java.util.List;

/**
 * <p>
 * 描述：流程信息service接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
public interface ProcessInfoService {

    /**
     * 根据用户id获得流程相关信息
     * @param id 用户id
     * @return 封装为List,获取到流程信息,获得待办，已办，待阅，已阅，草稿的数量
     */
    public ProcessInfoVo getProcessInfo(String id);

}
