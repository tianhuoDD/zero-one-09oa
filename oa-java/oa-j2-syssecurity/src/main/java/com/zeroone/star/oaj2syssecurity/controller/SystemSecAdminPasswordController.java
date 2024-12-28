package com.zeroone.star.oaj2syssecurity.controller;

import com.zeroone.star.oaj2syssecurity.entity.Person;
import com.zeroone.star.oaj2syssecurity.service.SystemSecAdminPasswordService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j2.system.security.password.AdminPasswordDTO;
import com.zeroone.star.project.j2.system.security.password.AdminPasswordApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.security.password.AdminPasswordVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.commons.codec.digest.DigestUtils;
import org.springframework.util.StringUtils;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.regex.Pattern;


/**
 * <p>
 * 描述：获取和保存管理员密码
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 红泥小火炉
 * @version 1.0.0
 */
@RestController
@RequestMapping("syssecurity/adminpassword")
@Api(tags = "登录配置")
public class SystemSecAdminPasswordController implements AdminPasswordApis {

    @Resource
    private UserHolder userHolder;

    @Resource
    private SystemSecAdminPasswordService service;

    @ApiOperation("获取管理员密码")
    @GetMapping("getAdminPassword")
    @Override
    public JsonVO<AdminPasswordVO> getAdminPassword() throws Exception {
        //获取管理员信息
        AdminPasswordVO admin = getCurrentAdmin();
        //返回
        //admin.setPassword(DigestUtils.md5Hex(admin.getPassword()));
        return JsonVO.success(admin);
    }

    @ApiOperation("保存管理员密码")
    @PutMapping("saveAdminPassword")
    @Override
    public JsonVO<Boolean> saveAdminPassword(AdminPasswordDTO dto) throws Exception {
        String oldPassword=dto.getOldPassword();
        String newPasswordOne=dto.getNewPasswordOne();
        String newPasswordTwo=dto.getNewPasswordTwo();
        //输入密码为空
        if(StringUtils.isEmpty(oldPassword) || StringUtils.isEmpty(newPasswordOne) || StringUtils.isEmpty(newPasswordTwo)){
            throw new RuntimeException("输入密码为空");
        }
        //两次密码输入不一致
        if (!newPasswordOne.equals(newPasswordTwo)){
            throw new RuntimeException("两次密码输入不一致");
        }
        //输入密码不符合规范
        String pattern = "[a-zA-Z0-9]{6,}";
        boolean isNormative = Pattern.matches(pattern, newPasswordOne);
        if(!isNormative){
            throw new RuntimeException("密码不符合规范,必须是数字,字母且至少 6位");
        }

        //获取管理员信息
        AdminPasswordVO admin = getCurrentAdmin();
        String xpassword = admin.getPassword();
        String secureOldPassword = DigestUtils.md5Hex(oldPassword);
        //比较原密码与数据库密码是否一样
        if(!secureOldPassword.equals(xpassword)){
            throw new RuntimeException("原密码错误");
        }

        //将管理员id，密码在数据库中更新
        String secureNewPassword = DigestUtils.md5Hex(newPasswordOne);
        Person person = new Person();
        person.setXid(admin.getId());
        person.setXpassword(secureNewPassword);

        int count = service.saveById(person);

        return JsonVO.success(count>0);
    }

    private AdminPasswordVO getCurrentAdmin() throws Exception {
        //根据请求头获取当前用户id
        UserDTO currentUser = userHolder.getCurrentUser();
        String id = currentUser.getId();
        System.out.println(id);
        //根据id查找用户信息
        AdminPasswordVO admin = service.getByXId(id);
        return admin;
    }
}
