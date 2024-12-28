package com.zeroone.star.project.j8.user;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user_identity.UserIdentityDTO;
import com.zeroone.star.project.query.j8.user.user_identity.UserIdentityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_identity.UserIdentityVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;

@Api("用户身份接口")
public interface UserIdentityApis {
    /**
     * 通过个人id获取个人身份信息(分页)
     * @param userIdentityQuery
     * @return 查询结果,用户分页信息
     */
    @ApiOperation(value = "获取个人身份信息（分页）", notes = "根据id查询个人身份信息并分页展示")
    JsonVO<PageDTO<UserIdentityVO>> getUserIdentity(UserIdentityQuery userIdentityQuery);

    /**
     * 通过传入人员身份信息数据对人员身份信息进行修改
     * @param userIdentityDTO
     * @return 操作结果
     */
    @ApiOperation(value = "修改个人身份信息")
    JsonVO<String> updateUserIdentity(UserIdentityDTO userIdentityDTO);

    /**
     * 修改主身份
     * @param xid 唯一标识
     * @return 操作结果
     */
    @ApiOperation("设置主身份")
    JsonVO<String> setPrimaryIdentity(String xid);
}
