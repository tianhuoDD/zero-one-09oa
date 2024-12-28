package com.zeroone.star.settings.controller;

import com.zeroone.star.project.dto.j1.person.setting.PersonInfohanDTO;
import com.zeroone.star.project.j1.person.PersonSettingApishan;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.person.setting.PersonInfohanVO;
import com.zeroone.star.settings.service.impl.QueryPersonSettingsHanServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("settings/person-setting")
@Api(tags = "个人设置")
public class PersonSettingController implements PersonSettingApishan {
    @Resource
    QueryPersonSettingsHanServiceImpl queryPersonSettingsHanService;

    @Override
    @GetMapping("person-info")
    @ApiOperation("查询个人资料")
    public JsonVO<PersonInfohanVO> queryPersonInfo(String id) {
        if (id == null || id.isEmpty()) {
            PersonInfohanVO personInfohanVO1 = new PersonInfohanVO();
            return JsonVO.success(personInfohanVO1);
        }
        PersonInfohanVO personInfohanVO = queryPersonSettingsHanService.getPersonInfohan(id);
        return JsonVO.success(personInfohanVO);
    }

}
