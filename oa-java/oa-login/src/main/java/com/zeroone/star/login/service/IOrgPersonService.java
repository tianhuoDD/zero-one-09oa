package com.zeroone.star.login.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.j1.userInfo.UserInfoVO;
import com.zeroone.star.login.entity.OrgPerson;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.j1.forgotPassword.SmsVerificationDTO;
import com.zeroone.star.project.vo.j1.forgotPassword.NewPasswordVO;

/**
* @author 29720
* @description 针对表【org_person】的数据库操作Service
* @createDate 2024-10-21 17:42:34
*/
public interface IOrgPersonService extends IService<OrgPerson> {
	/**
	 * 获取当前用户信息
	 * @param currentUser
	 * @return
	 */
	UserInfoVO getUserInfo(UserDTO currentUser);
	/**
	 * 根据手机号查询验证信息
	 * @param xmobile 手机号
	 * @return 用户信息
	 */
	SmsVerificationDTO getVerificationByXmobile(String xmobile);

	/**
	 * 根据用户名修改密码
	 * @param xmobile 手机号
	 * @param password 新密码
	 * @return 用户信息
	 */
	NewPasswordVO updatePassword(String xmobile, String password, String confirmPassword);
}
