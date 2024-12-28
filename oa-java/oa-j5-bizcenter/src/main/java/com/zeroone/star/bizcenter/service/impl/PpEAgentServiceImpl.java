package com.zeroone.star.bizcenter.service.impl;

import com.zeroone.star.bizcenter.entity.PpEAgent;
import com.zeroone.star.bizcenter.entity.PpEAgentReaddatapathlist;
import com.zeroone.star.bizcenter.service.IPpEAgentService;
import com.zeroone.star.bizcenter.mapper.PpEAgentMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Service
public class PpEAgentServiceImpl extends ServiceImpl<PpEAgentMapper, PpEAgent> implements IPpEAgentService {

    @Resource
    PpEAgentMapper ppEAgentMapper;


    @Override
    public List<PpEAgentReaddatapathlist> getReaddatapathlist(List<String> ids) {
        return ppEAgentMapper.getReaddatapathlist(ids);
    }
}
