package com.zeroone.star.project.dto.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：共享用户传输数据对象
 * </p>
 * @author qi
 * @version 1.0.0
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("共享用户传输数据对象")
public class ShareUserDTO {

    @ApiModelProperty(value = "用户ID", example = "1")
    private Long userId;

    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;

    @ApiModelProperty(value = "邮箱", example = "lisi@example.com")
    private String email;

    @ApiModelProperty(value = "联系电话", example = "13800138000")
    private String phone;

    @ApiModelProperty(value = "共享角色", example = "领导")
    private String role;
}
