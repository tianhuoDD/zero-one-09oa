package com.zeroone.star.project.query.j8.user.user_info;

import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.io.Serializable;

/**
 * @author 西北卓越青年
 */
@Data
@ApiModel("通过唯一编码查询用户信息")
public class UserInfoQuery implements Serializable {
    private static final long serialVersionUID = 1L;
    //唯一编码
    private String xunique;
}
