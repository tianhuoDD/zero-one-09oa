package com.zeroone.star.cmshome.controller;

import com.zeroone.star.project.j5.cmshome.PublishMessageApis;
import com.zeroone.star.cmshome.service.IPublishMessageService;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @Description: 消息管理-发布消息
 * @Param:
 * @return:
 * @Author:王星峰
 * @Date:
 */
@RestController
@RequestMapping("cmshome")
@Api(tags = "消息管理")
@Validated
public class PublishMessageController implements PublishMessageApis {

    @Resource
    private IPublishMessageService publishMessageService;
    @ApiOperation("发布消息")
    @PostMapping("/publish-message")
    @Override
    public JsonVO<Boolean> publishMessage(@RequestBody @Validated PublishMessageDTO publishMessageDTO) {

        if (publishMessageDTO == null) {
            throw new IllegalArgumentException("PublishMessageDTO cannot be null");
        }

        boolean save = publishMessageService.save(publishMessageDTO);
        return JsonVO.success(save);
    }


}
