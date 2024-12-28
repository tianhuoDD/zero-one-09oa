package com.zeroone.star.project.j8.user;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user.AddPersonDTO;
import com.zeroone.star.project.dto.j8.user.user.PersonDTO;
import com.zeroone.star.project.dto.j8.user.user.UpdatePersonDTO;
import com.zeroone.star.project.query.j8.user.user.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;

@Api(tags = "用户管理接口")
public interface UserApis {

    /**
     * 分页查询用户信息
     * @param condition 查询条件
     * @return 查询结果，包含用户分页信息
     */
    @ApiOperation("分页查询用户信息")
    JsonVO<PageDTO<PersonDTO>> queryAll(UserQuery condition);

    /**
     * 根据ID查询用户信息
     * @param xid 用户唯一标识
     * @return 查询结果，包含单个用户信息
     */
    @ApiOperation("根据ID查询用户信息")
    JsonVO<PersonDTO> queryById(String xid);

    /**
     * 添加新用户
     * @param userDTO 用户信息
     * @return 操作结果
     */
    @ApiOperation("添加新用户")
    JsonVO<String> addUser(AddPersonDTO userDTO);

    /**
     * 更新用户信息
     * @param userDTO 用户信息
     * @return 操作结果
     */
    @ApiOperation("更新用户信息")
    JsonVO<String> updateUser(UpdatePersonDTO userDTO);

    /**
     * 删除用户信息
     * @param xid 用户唯一标识
     * @return 操作结果
     */
    @ApiOperation("删除用户信息")
    JsonVO<String> deleteUser(String xid);
}

