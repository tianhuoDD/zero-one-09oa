package com.zeroone.star.login.controller;


import cn.hutool.core.bean.BeanUtil;
import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.project.vo.j1.userInfo.UserInfoVO;
import com.zeroone.cloud.oauth2.entity.Oauth2Token;
import com.zeroone.star.login.mapper.OrgRoleMapper;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.login.service.IOrgPersonService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.dto.login.RefreshTokenDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("login")
@Slf4j
@Api(tags = "login")
public class LoginController implements LoginApis {

    @Resource
    RedisTemplate<String, Object> redisTemplate;
    @Resource
    CaptchaService captchaService;
    @Resource
    OauthService oAuthService;
    @Resource
    UserHolder userHolder;
    @Value("${zo.cloud.starter.oauth2.mgr-id}")
    String clientId;
    @Value("${zo.cloud.starter.oauth2.mgr-password}")
    String clientPassword;

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        // 验证码验证
        CaptchaVO captchaVO = new CaptchaVO();
        captchaVO.setCaptchaVerification(loginDTO.getCode());
        ResponseModel response = captchaService.verification(captchaVO);
        // if (!response.isSuccess()) {
        //     return JsonVO.create(null, Integer.parseInt(response.getRepCode()), CodeStatus.getMessageByCode(response.getRepCode()));
        // }
        // 账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);

        // 认证失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }
        //将登录凭证保存到redis中
        redisTemplate.opsForValue().set(loginDTO.getUsername(),oauth2Token);

        // 响应认证成功数据
        return JsonVO.success(BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class));
    }



    @SneakyThrows
    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(RefreshTokenDTO refreshTokenDTO) {
        // 注销凭证
        if (refreshTokenDTO.getToken() != null) {
            // 实现注销凭证验证
            redisTemplate.delete(userHolder.getCurrentUser().getUsername());
        }

        // 刷新凭证
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("refresh_token", refreshTokenDTO.getRefreshToken());
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);

        // 刷新失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }

        //将登录凭证保存到redis中
        redisTemplate.opsForValue().set(userHolder.getCurrentUser().getUsername(),oauth2Token);

        // 响应刷新成功数据
        return JsonVO.success(BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class));
    }

    @Resource
    private IOrgPersonService orgPersonService;

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<UserInfoVO> getCurrUser() {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        } else {
            UserInfoVO userInfoVO = orgPersonService.getUserInfo(currentUser);
            return JsonVO.success(userInfoVO);
        }
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        // 获取当前请求的token
        String token = userHolder.getCurrentToken();
        if (token != null) {
            // TODO:登出逻辑，需要配合登录逻辑实现
            return JsonVO.success("退出成功");
        }
        return JsonVO.fail("获取凭证失败，退出失败");
    }

    @Resource
    IMenuService menuService;

    @Autowired
    private OrgRoleMapper orgRoleMapper;
    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<MenuTreeVO>> getMenus() throws Exception {
        // TODO:未实现根据实际数据库设计业务逻辑，下面逻辑属于示例逻辑
        // 1 获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        // 2 获取当前用户拥有的菜单
        if (currentUser == null || currentUser.getId() == null) {
            return JsonVO.fail(new ArrayList<>());
        }
        String id = currentUser.getId();
        List<String> roles = orgRoleMapper.getRolesByUserId(id);
        List<MenuTreeVO> menus = menuService.listMenuByRoleName(roles);
        return JsonVO.success(menus);
    }
}
