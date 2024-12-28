package com.zeroone.star.cmshome.controller;

import com.zeroone.star.project.j5.cmshome.DeleteMessageApis;
import com.zeroone.star.cmshome.service.IDeleteMessageService;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * @Description: 消息管理-删除消息
 * @Param:
 * @return:
 * @Author: 王星峰
 * @Date:
 */
@RestController
@RequestMapping("cmshome")
@Api(tags = "消息管理")
@Validated
public class DeleteMessageController implements DeleteMessageApis {


    @Resource
    private IDeleteMessageService iDeleteMessageService;

    @ApiOperation("删除消息")
    @DeleteMapping("/delete-message")
    @Override
    public JsonVO<Boolean> deleteMessage(@RequestParam @Validated List<String> ids) {
        boolean delete = iDeleteMessageService.delete(ids);
        return JsonVO.success(delete);
    }
}
