package com.zeroone.star.user.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user.AddPersonDTO;
import com.zeroone.star.project.dto.j8.user.user.PersonDTO;
import com.zeroone.star.project.dto.j8.user.user.UpdatePersonDTO;
import com.zeroone.star.project.j8.user.UserApis;
import com.zeroone.star.project.query.j8.user.user.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.user.services.OrgPersonService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import javax.annotation.Resource;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "用户接口")
@RestController
@RequestMapping("/org/user")
public class UserController implements UserApis {

    @Resource
    private OrgPersonService orgPersonService; // 注入服务

    @Override
    @PostMapping("/query")
    @ApiOperation("分页查询用户信息")
    public JsonVO<PageDTO<PersonDTO>> queryAll(@RequestBody UserQuery condition) {
        PageDTO<PersonDTO> personPage = orgPersonService.getPersonList(condition).getData();
        return JsonVO.success(personPage);
    }

    @Override
    @GetMapping("/{xid}")
    @ApiOperation("根据ID查询用户信息")
    public JsonVO<PersonDTO> queryById(@PathVariable String xid) {
        PersonDTO personDTO = orgPersonService.getPersonById(xid);
        return JsonVO.success(personDTO);
    }

    @Override
    @PostMapping("/adduser")
    @ApiOperation("添加新用户")
    public JsonVO<String> addUser(@RequestBody AddPersonDTO userDTO) {
        orgPersonService.addPerson(userDTO);
        return JsonVO.success("人员添加成功");
    }

    @Override
    @PutMapping("/updateuser")
    @ApiOperation("更新用户信息")
    public JsonVO<String> updateUser(@RequestBody UpdatePersonDTO userDTO) {
        orgPersonService.updatePerson(userDTO);
        return JsonVO.success("人员信息更新成功");
    }

    @Override
    @DeleteMapping("/delete/user/{xid}")
    @ApiOperation("删除用户信息")
    public JsonVO<String> deleteUser(@PathVariable String xid) {
        orgPersonService.deletePerson(xid);
        return JsonVO.success("人员删除成功");
    }
}
