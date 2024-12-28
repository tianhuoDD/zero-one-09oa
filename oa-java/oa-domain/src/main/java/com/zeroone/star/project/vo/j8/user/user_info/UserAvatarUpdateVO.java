package com.zeroone.star.project.vo.j8.user.user_info;

import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.io.Serializable;

/**
 * @author 西北卓越青年
 */
@Data
@ApiModel("修改头像vo 返回头像url")
public class UserAvatarUpdateVO implements Serializable {
    private static final long serialVersionUID = 1L;
    //头像url
    private String avatarUrl;
}
