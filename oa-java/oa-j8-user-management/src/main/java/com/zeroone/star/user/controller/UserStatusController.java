package com.zeroone.star.user.controller;

import com.zeroone.star.project.j8.user.UserStatusApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.user.services.OrgPersonService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import java.util.Date;
import javax.annotation.Resource;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@Slf4j
@Api(tags = "用户状态接口")
@RequestMapping("/org/user")
public class UserStatusController implements UserStatusApis {

    @Resource
    private OrgPersonService personService;

    @PutMapping("/{user_id}/disable")
    @ApiOperation("禁用")
    public JsonVO<String> disableUser(@PathVariable String user_id) {
        try {
            personService.disableUserByID(user_id);
            return JsonVO.success("用户已禁用");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    //解禁
    @PutMapping("/{user_id}/enable")
    @ApiOperation("解禁")
    public JsonVO<String> enableUser(@PathVariable String user_id) {
        try {
            personService.enableUser(user_id);
            return JsonVO.success("用户已解禁");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    // 锁定用户
    @PutMapping("/{user_id}/lock")
    @ApiOperation("锁定用户")
    public JsonVO<String> lockUser(@PathVariable String user_id) {
        try {
            personService.lockUser(user_id);
            return JsonVO.success("用户已锁定");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    // 解锁用户
    @PutMapping("/{user_id}/unlock")
    @ApiOperation("解锁用户")

    public JsonVO<String> unlockUser(@PathVariable String user_id) {
        try {
            personService.unlockUser(user_id);
            return JsonVO.success("用户已解锁");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    // 设置密码过期时间
    @PutMapping("/{user_id}/password-expiration")
    @ApiOperation("设置密码过期时间")
    public JsonVO<String> setPasswordExpiration(@PathVariable String user_id,
        @RequestParam Date expirationDate) {
        String xlocktime = personService.setPasswordExpirationByID(user_id, expirationDate);
        return JsonVO.success("密码过期时间为" + xlocktime);
    }

    // 重置用户密码
    @PutMapping("/{user_id}/reset-password")
    @ApiOperation("重置用户密码")
    public JsonVO<String> resetUserPassword(@PathVariable String user_id) {
        personService.resetUserPasswordByid(user_id);
        return JsonVO.success("密码已重置");
    }

}
