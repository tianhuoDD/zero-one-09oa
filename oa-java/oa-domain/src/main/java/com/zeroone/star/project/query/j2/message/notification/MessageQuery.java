package com.zeroone.star.project.query.j2.message.notification;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @Author: hjm
 * @Date: 2024/10/20/16:26
 * @Description: 消息查询对象
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("消息查询对象")
public class MessageQuery extends PageQuery {
    /**
     * 用户ID
     */
    @ApiModelProperty(value = "用户ID", example = "1")
    private String xperson;

    /**
     * 是否已读
     */
    @ApiModelProperty(value = "是否已读", example = "false")
    private Boolean xconsumed;
}