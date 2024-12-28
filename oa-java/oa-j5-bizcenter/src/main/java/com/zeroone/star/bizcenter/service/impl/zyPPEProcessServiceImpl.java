package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.zyPPEProcess;
import com.zeroone.star.bizcenter.mapper.zyPPEProcessMapper;
import com.zeroone.star.bizcenter.service.zyPPEProcessService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class zyPPEProcessServiceImpl extends ServiceImpl<zyPPEProcessMapper, zyPPEProcess> implements zyPPEProcessService {
    @Autowired
    private zyPPEProcessMapper zyPpeProcessMapper;

    /**
     *  根据应用id 查找流程列表
     * @param appId 应用id
     * @return 流程列表
     */
    public List<zyPPEProcess> listProcessListByAppId(String appId) {
        QueryWrapper<zyPPEProcess> queryWrapper2 = new QueryWrapper<>();
        queryWrapper2.eq("xapplication", appId);
        List<zyPPEProcess> zyPpeProcesses = zyPpeProcessMapper.selectList(queryWrapper2);
        if (zyPpeProcesses.isEmpty()) {
            throw new RuntimeException("流程列表为空");
        }
        return zyPpeProcesses;
    }
}
