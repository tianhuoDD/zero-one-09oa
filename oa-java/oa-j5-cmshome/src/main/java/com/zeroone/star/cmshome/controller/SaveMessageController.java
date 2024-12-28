package com.zeroone.star.cmshome.controller;


import com.zeroone.star.project.j5.cmshome.SaveMessageApis;
import com.zeroone.star.cmshome.service.ISaveMessageService;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
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
 * @Description: 消息管理-保存草稿
 * @Param:
 * @return:
 * @Author: 王星峰
 * @Date:
 */
@RestController
@RequestMapping("cmshome")
@Api(tags = "消息管理")
@Validated
public class SaveMessageController implements SaveMessageApis {

    @Resource
    private ISaveMessageService saveMessageService;

    @ApiOperation("保存草稿")
    @PostMapping("/save-message")
    @Override
    public JsonVO<Boolean> saveMessage(@RequestBody @Validated PublishMessageDTO publishMessageDTO) {
        if (publishMessageDTO == null) {
            throw new IllegalArgumentException("PublishMessageDTO cannot be null");
        }

        boolean save = saveMessageService.save(publishMessageDTO);
        return JsonVO.success(save);
    }


}
