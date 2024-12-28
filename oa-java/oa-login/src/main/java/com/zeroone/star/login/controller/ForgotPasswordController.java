package com.zeroone.star.login.controller;


import com.zeroone.star.login.service.IOrgPersonService;
import com.zeroone.star.project.dto.j1.forgotPassword.NewPasswordDTO;
import com.zeroone.star.project.dto.j1.forgotPassword.SmsVerificationDTO;
import com.zeroone.star.project.j1.forgotPassword.NewPasswordApis;
import com.zeroone.star.project.j1.forgotPassword.SmsVerificationApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.forgotPassword.NewPasswordVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

@RestController
@RequiredArgsConstructor
@RequestMapping("login/forgotPassword")
@Api(tags = "忘记密码")
public class ForgotPasswordController implements NewPasswordApis, SmsVerificationApis {

    private final IOrgPersonService personService;

    @PutMapping("modifyPassword")
    @ApiOperation("修改密码")
    @Override
    public JsonVO<NewPasswordVO> modifyNewPassword(@RequestBody NewPasswordDTO newPasswordDTO) {

        return JsonVO.success(personService.updatePassword(newPasswordDTO.getXmobile(), newPasswordDTO.getNewPassword(), newPasswordDTO.getConfirmPassword()));
    }
    @GetMapping("querySms")
    @ApiOperation("查询手机号返回验证码")
    @Override
    public JsonVO<SmsVerificationDTO> querySmsVerification(@RequestParam String xmobile) {

        return JsonVO.success(personService.getVerificationByXmobile(xmobile));
    }

}
