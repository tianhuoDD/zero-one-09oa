package com.zeroone.star.systemhome.service.messge;

import com.zeroone.star.project.dto.j1.message.getting.PromulgationMessageInfoDTO;

import java.util.List;

/**
 * @description: 获取信息的接口
 * @author: dashuai
 * @date: 2024/10/27 11:24
 * @param:
 * @return:
 **/
public interface PromulgationMessageInfoService {

    List<PromulgationMessageInfoDTO> listPMI(String personId);
}
