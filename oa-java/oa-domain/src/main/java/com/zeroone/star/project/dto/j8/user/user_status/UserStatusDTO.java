package com.zeroone.star.project.dto.j8.user.user_status;

import java.sql.Date;
import lombok.Data;

@Data
public class UserStatusDTO {
    private Long id;
    private String username;
    private String password;
    private boolean enabled; // 禁用/启用
    private boolean accountNonLocked; // 锁定/解锁
    private Date passwordExpires; // 密码过期时间
}
