package com.zeroone.star.project.dto.j1.person.setting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：用户信息操作对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
public class PersonInfohanDTO {
    /**
     * 用户id
     */
    @ApiModelProperty(value = "唯一标识", example = "12ass22sa3")
    private String id;
    /**
     * 办公电话
     */
    @ApiModelProperty(value = "办公电话", example = "029-11212121")
    private String telphone;
    /**
     * 微信
     */
    @ApiModelProperty(value = "微信", example = "xilhea")
    private String weixin;
    /**
     * QQ
     */
    @ApiModelProperty(value = "QQ", example = "1234545678")
    private Long qq;
    /**
     * 论坛名称
     */
    @ApiModelProperty(value = "论坛名称", example = "飞翔的猪")
    private String bbsname;
    /**
     * 个性签名
     */
    @ApiModelProperty(value = "个性签名", example = "没有个性签名")
    private String single;
}
