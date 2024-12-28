package com.zeroone.star.project.j1.system.home;


import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.system.home.ProcessInfoVo;

import java.util.List;

/**
 * <p>
 * 描述：流程信息相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
public interface ProcessInfoApis {
    /**
     * 获取我的流程信息
     * @param id 用户id
     * @return 获取到的我的流程信息,获得已办，代办，已阅，待阅，草稿的数量
     */
    public JsonVO<ProcessInfoVo> queryProcessInfo(String id);
}
