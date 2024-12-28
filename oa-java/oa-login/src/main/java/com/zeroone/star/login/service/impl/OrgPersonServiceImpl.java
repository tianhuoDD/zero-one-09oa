package com.zeroone.star.login.service.impl;


import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.j1.userInfo.UserInfoVO;
import com.zeroone.star.login.entity.OrgPerson;
import com.zeroone.star.login.mapper.OrgPersonMapper;
import com.zeroone.star.login.mapper.OrgRoleMapper;
import com.zeroone.star.login.service.IOrgCustomService;
import com.zeroone.star.login.service.IOrgPersonService;
import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.j1.forgotPassword.OrgPersonDTO;
import com.zeroone.star.project.dto.j1.forgotPassword.SmsVerificationDTO;
import com.zeroone.star.project.utils.md5Encryption.MD5Util;
import com.zeroone.star.project.vo.j1.forgotPassword.NewPasswordVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

/**
 * @author 29720
 * @description 针对表【org_person】的数据库操作Service实现
 * @createDate 2024-10-21 17:42:34
 */
@Service
public class OrgPersonServiceImpl extends ServiceImpl<OrgPersonMapper, OrgPerson> implements IOrgPersonService {
	@Resource
	private IOrgCustomService orgCustomService;
	@Resource
	private OrgPersonMapper orgPersonMapper;
	private final static String LAYOUT = "layout";

	@Autowired
	private OrgRoleMapper orgRoleMapper;

	@Override
	public UserInfoVO getUserInfo(UserDTO currentUser) {
		String id = currentUser.getId();
		if (id == null || id.isEmpty()) {
			return null;
		}
		// 获取用户详细信息
		OrgPerson orgPerson = orgPersonMapper.getUserInfoById(id);
		// 复制属性
		UserInfoVO userInfoVO = BeanUtil.copyProperties(orgPerson, UserInfoVO.class);
		// 脱敏
		userInfoVO.setXpassword(null);
		// List<String> roles = currentUser.getRoles();
		// if (roles != null && !roles.isEmpty()) {
		// 	userInfoVO.setRoles(roles);
		// }
		List<String> roles = orgRoleMapper.getRolesByUserId(id);
		userInfoVO.setRoles(roles);
		// //  设置主页导航栏
		// // 这是我的名称@bianma@P
		// String xdistinguishedName = userInfoVO.getXdistinguishedName();
		// OrgCustom orgCustom = orgCustomService.getOne(
		// 		new LambdaQueryWrapper<OrgCustom>()
		// 				.eq(OrgCustom::getXperson, xdistinguishedName)
		// 				.eq(OrgCustom::getXname, LAYOUT)
		// );
		// String xdata = orgCustom.getXdata();
		// userInfoVO.setMenuTreeVO(null);
		return userInfoVO;
	}


	@Resource
	SmsComponent smsComponent;

	@Override
	public SmsVerificationDTO getVerificationByXmobile(String xmobile) {
		// 1. 查询用户信息
		Wrapper<OrgPerson> wrapper = new LambdaQueryWrapper<OrgPerson>()
											 .eq(OrgPerson::getXmobile, xmobile);
		OrgPerson personObject = baseMapper.selectOne(wrapper);
		OrgPersonDTO person = BeanUtil.copyProperties(personObject, OrgPersonDTO.class);
		if (person == null) {
			return new SmsVerificationDTO().setMessage("用户不存在");
		}
		// 2. 生成验证码
		String verificationCode = generateVerificationCode();

		// 3. 发送短信
		Map<String, String> templateParams = new HashMap<>();
		templateParams.put("code", verificationCode);
		SmsResult smsResult = smsComponent.sendSms(person.getXmobile(), "凯尔希CRM", "SMS_475010449", templateParams);


		if (!"OK".equals(smsResult.getCode())) {
			return new SmsVerificationDTO().setMessage("发送消息失败");
		}

		// 4. 封装 SmsVerificationDTO 对象
		SmsVerificationDTO smsVerificationDTO = new SmsVerificationDTO();
		smsVerificationDTO.setSmsCode(verificationCode);
		smsVerificationDTO.setMessage("发送成功");

		// 5. 返回 SmsVerificationDTO 对象
		return smsVerificationDTO;
	}

	// 生成验证码的方法
	private String generateVerificationCode() {
		// 生成6位随机数字作为验证码
		Random random = new Random();
		int code = 100000 + random.nextInt(900000);
		return String.valueOf(code);
	}

	@Override
	public NewPasswordVO updatePassword(String xmobile, String password, String confirmPassword) {
		// 检查新密码和确认密码是否一致
		if (!password.equals(confirmPassword)) {
			return new NewPasswordVO(null, "新密码与确认密码不一致");
		}
		// 查询用户
		LambdaQueryWrapper<OrgPerson> wrapper = new LambdaQueryWrapper<OrgPerson>()
														.eq(OrgPerson::getXmobile, xmobile);

		OrgPerson person = baseMapper.selectOne(wrapper);
		// 检查用户是否存在
		if (person == null) {
			return new NewPasswordVO(null, "用户不存在");
		}

		// 使用MD5加密新密码
		String encryptedPassword = MD5Util.encrypt(password);

		// 更新密码
		person.setXpassword(encryptedPassword);
		baseMapper.updateByXMobile(person);
		return null;
	}
}
