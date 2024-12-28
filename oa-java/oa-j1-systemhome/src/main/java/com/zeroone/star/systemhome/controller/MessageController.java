package com.zeroone.star.systemhome.controller;

import com.zeroone.star.project.dto.j1.message.getting.PromulgationMessageInfoDTO;
import com.zeroone.star.project.j1.message.GetPromulgationMessageInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.message.getting.PromulgationMessageInfoVO;
import com.zeroone.star.systemhome.service.impl.message.PromulgationMessageInfoImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.systemhome.controller
 * @Author: dashuai
 * @CreateTime: 2024-10-21  19:23
 * @Description: 获取别人发布的消息的有关信息
 * @Version: 1.0
 */

@RestController
@Api(tags = "获取别人发布的消息的有关信息的接口")
@RequestMapping("/systemhome/message")
@RequiredArgsConstructor
public class MessageController implements GetPromulgationMessageInfoApis {

    private final PromulgationMessageInfoImpl pmii;

    /**
     * @description: 获取别人发布的消息的有关信息
     * @author: dashuai
     * @date: 2024/10/21 19:36
     * @param: [PersonId] 登录人id
     * @return: List<JsonVO<PromulgationMessageInfoVO>> 发布的信息的有关信息列表
     **/
    @ApiOperation(value = "获取别人发布的消息的有关信息")
    @GetMapping("/query-promulgationMessageInfo")
    @Override
    public JsonVO<List<PromulgationMessageInfoDTO>> queryPromulgationMessageInfo(@RequestParam String personId) {
        return JsonVO.success(pmii.listPMI(personId));
    }
}
