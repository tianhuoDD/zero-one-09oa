package com.zeroone.star.project.j8.user;

import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import java.util.Date;
import javax.validation.constraints.NotNull;

public interface UserStatusApis {

    public JsonVO<String> disableUser(String user_id);

    //解禁
    public JsonVO<String> enableUser(String user_id);

    // 锁定用户
    public JsonVO<String> lockUser(String user_id);

    // 解锁用户
    public JsonVO<String> unlockUser(String user_id);

    // 设置密码过期时间
    public JsonVO<String> setPasswordExpiration(String user_id, Date expirationDate);

    // 重置用户密码
    public JsonVO<String> resetUserPassword(String user_id);
}
