package com.zeroone.star.project.j2.system.security.password;

import com.zeroone.star.project.dto.j2.system.security.password.AdminPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.security.password.AdminPasswordVO;
import io.swagger.annotations.ApiOperation;

/**
 * <p>
 * 描述：获取和保存管理员密码
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 红泥小火炉
 * @version 1.0.0
 */
public interface AdminPasswordApis {

    /**
     * 获取管理员密码
     * @return 管理员密码对象
     */
    @ApiOperation("获取管理员密码")
    JsonVO<AdminPasswordVO> getAdminPassword() throws Exception;

    /**
     * 保存管理员密码
     * param 管理员密码对象
     * @return 保存是否成功
     */
    @ApiOperation("保存管理员密码")
    JsonVO<Boolean> saveAdminPassword(AdminPasswordDTO dto) throws Exception;
}