package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpEAgent;
import com.zeroone.star.bizcenter.entity.PpEAgentReaddatapathlist;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
public interface IPpEAgentService extends IService<PpEAgent> {

    List<PpEAgentReaddatapathlist> getReaddatapathlist(List<String> ids);
}
