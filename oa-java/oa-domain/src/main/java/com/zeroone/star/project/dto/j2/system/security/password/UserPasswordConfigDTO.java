package com.zeroone.star.project.dto.j2.system.security.password;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.validator.constraints.Range;

import javax.validation.constraints.Min;
import java.util.List;

/**
 * 用户密码配置显示对象
 * @author JIAN
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel(description = "用户密码配置修改对象(参数为空值不修改支持多传)")
public class UserPasswordConfigDTO {
    /**
     * 初始密码生成方式
     * 1. 手机号码后六位
     * 2. 唯一编码后六位
     * 3. 人员工号
     * 4. 人员名称全拼
     * 5. 固定口令
     * 6. 通过脚本自定义生成密码
     */
    @Range(min = 1, max = 6)
    @ApiModelProperty(value = "初始密码生成方式 1.手机号码后六位 2.唯一编码后六位 3.人员工号 4.人员名称全拼 5.固定口令 6.通过脚本自定义生成密码",
            example = "1", allowableValues = "range[1,6]")
    private Integer defaultPasswordGenerateWay;

    /**
     * 初始密码生成的额外信息, 生成方式指定为
     * 5 -> 口令内容
     * 6 -> 脚本内容
     * 其他情况无效
     */
    @ApiModelProperty(value = "初始密码生成的额外信息 5->口令内容 6->脚本内容", example = "null")
    private String defaultPasswordAdditionInfo;

    /**
     * 密码过期天数(0表示永不过期)
     */
    @Min(0)
    @ApiModelProperty(value = "密码过期天数(0表示永不过期)", example = "0", allowableValues = "range[0,infinity]")
    private Integer passwordExpireTime;

    /**
     * 最小密码长度
     */
    @Range(min = 1, max = 30)
    @ApiModelProperty(value = "最小密码长度", example = "8", allowableValues = "range[1,30]")
    private Integer passwordLengthMin;

    /**
     * 最大密码长度
     */
    @Range(min = 1, max = 30)
    @ApiModelProperty(value = "最大密码长度", example = "30", allowableValues = "range[1,30]")
    private Integer passwordLengthMax;

    /**
     * 密码满足的规则(规则名列表形式返回), 可能的规则如下
     * 1. 必须包含小写字母
     * 2. 必须包含数字
     * 3. 必须包含大写字母
     * 4. 必须包含特殊字符(#?!@$%^&*-)
     */
    @ApiModelProperty(value = "密码规则列表", example = "['必须包含小写字母','必须包含数字','必须包含大写字母','必须包含特殊字符(#?!@$%^&*-)']")
    private List<String> passwordRule;

    /**
     * 密码是否加密传输
     */
    @ApiModelProperty(value = "密码加密传输", example = "false")
    private Boolean isEnableEncryptedSend;

    /**
     * 密码是否强制修改
     */
    @ApiModelProperty(value = "密码强制修改", example = "false")
    private Boolean isEnableForceChange;
}