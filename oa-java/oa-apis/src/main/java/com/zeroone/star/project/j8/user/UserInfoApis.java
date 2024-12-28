package com.zeroone.star.project.j8.user;

import com.zeroone.star.project.dto.j8.user.user_info.UserInfoUpdateDTO;
import com.zeroone.star.project.query.j8.user.user_info.UserInfoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_info.UserInfoVO;

public interface UserInfoApis {

//    public JsonVO<UserAvatarUpdateVO> modifyUserAvatar(Object file);

    public JsonVO<String> modifyUserInfo(UserInfoUpdateDTO userInfoUpdateDTO);

    public JsonVO<UserInfoVO> queryUserInfo(UserInfoQuery userInfoQuery);
}
