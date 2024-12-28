package com.zeroone.star.systemhome.service.impl.message;

import com.zeroone.star.project.dto.j1.message.getting.PromulgationMessageInfoDTO;
import com.zeroone.star.systemhome.mapper.message.PromulgationMessageInfoMapper;
import com.zeroone.star.systemhome.service.messge.PromulgationMessageInfoService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.systemhome.service.impl.message
 * @Author: dashuai
 * @CreateTime: 2024-10-27  11:26
 * @Description: 实现接收消息的接口
 * @Version: 1.0
 */
@Service
@RequiredArgsConstructor
public class PromulgationMessageInfoImpl implements PromulgationMessageInfoService {
    private final PromulgationMessageInfoMapper pmim;

    /**
     * @description: 查询接收消息
     * @author: dashuai
     * @date: 2024/10/27 11:50
     * @param: [personId] 登录人id
     * @return: List<PromulgationMessageInfoDTO>
     **/
    @Override
    public List<PromulgationMessageInfoDTO> listPMI(String personId) {
        return pmim.selectPMI(personId);
    }
}
