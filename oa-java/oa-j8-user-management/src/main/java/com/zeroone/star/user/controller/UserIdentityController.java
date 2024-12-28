package com.zeroone.star.user.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user_identity.UserIdentityDTO;
import com.zeroone.star.project.j8.user.UserIdentityApis;
import com.zeroone.star.project.query.j8.user.user_identity.UserIdentityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_identity.UserIdentityVO;
import com.zeroone.star.user.services.OrgIdentityService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import javax.annotation.Resource;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "用户身份接口")
@RestController
@RequestMapping("/org/user/identity")
public class UserIdentityController implements UserIdentityApis {

    @Resource
    private OrgIdentityService orgIdentityService;

    @PostMapping("/query")
    @ApiOperation("查询用户身份")
    @Override
    public JsonVO<PageDTO<UserIdentityVO>> getUserIdentity(@RequestBody UserIdentityQuery userIdentityQuery) {
        return JsonVO.success(orgIdentityService.getIdentityList(userIdentityQuery).getData());
    }

    @PutMapping("/update")
    @ApiOperation("更新用户身份")
    @Override
    public JsonVO<String> updateUserIdentity(@RequestBody UserIdentityDTO userIdentityDTO) {
        orgIdentityService.updateUserIdentity(userIdentityDTO);
        return JsonVO.success("更新用户身份成功");
    }

    @ApiOperation("设置用户主身份")
    @GetMapping(value = "/set-primary/{xid}")
    @Override
    public JsonVO<String> setPrimaryIdentity(@PathVariable String xid) {
        UserIdentityDTO userIdentityDTO = new UserIdentityDTO();
        userIdentityDTO.setXid(xid);
        userIdentityDTO.setXmajor(true);
        orgIdentityService.updateUserIdentity(userIdentityDTO);
        return JsonVO.success("设置用户主身份成功");
    }
}
