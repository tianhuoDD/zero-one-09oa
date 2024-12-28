package com.zeroone.star.project.vo.j2.message.notification;

import com.baomidou.mybatisplus.annotation.TableLogic;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @Author: hjm
 * @Date: 2024/10/20/16:23
 * @Description: 消息显示对象
 */
@Data
@ApiModel("消息显示对象")
public class MessageVO {
    /**
     * 消息ID
     */
    @ApiModelProperty(value = "消息ID", example = "1")
    private String xid;

    /**
     * 用户ID
     */
    @ApiModelProperty(value = "用户ID", example = "1")
    private String xperson;

    /**
     * 消息内容
     */
    @ApiModelProperty(value = "消息内容", example = "您有一条新消息")
    private String xbody;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2024-04-20T10:00:00")
    private Date xcreateTime;

    /**
     * 是否已读
     */
    @ApiModelProperty(value = "是否已读", example = "false")
    private Boolean xconsumed;

    /**
     * 消息标题
     */
    @ApiModelProperty(value = "消息标题", example = "重要通知")
    private String xtitle;

    /**
     * 消息类型
     */
    @ApiModelProperty(value = "消息类型", example = "通知")
    private String xtype;
}
