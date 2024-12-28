package com.zeroone.star.project.vo.j5.cmshome.form;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 描述：消息表单数据
 *
 * @author Henry
 */
@Data
@ApiModel("表单数据")
public class FormDataVO {
    /**
     * 唯一标识
     */
    @ApiModelProperty("唯一标识")
    private String xid;
    /**
     * 消息创建时间
     */
    @ApiModelProperty("消息创建时间")
    private LocalDateTime xcreateTime;
    /**
     * 消息次序
     */
    @ApiModelProperty("消息次序")
    private String xsequence;
    /**
     * 消息更新时间
     */
    @ApiModelProperty("消息更新时间")
    private LocalDateTime xupdateTime;
    /**
     * 消息分配因子
     */
    @ApiModelProperty("消息分配因子")
    private Integer xdistributeFactor;
    /**
     * 消息别名
     */
    @ApiModelProperty("消息别名")
    private String xalias;
    /**
     * 消息id
     */
    @ApiModelProperty("消息id")
    private String xappId;
    /**
     * 消息数据
     */
    @ApiModelProperty("消息数据")
    private String xdata;
    /**
     * 消息描述
     */
    @ApiModelProperty("消息描述")
    private String xdescription;
    /**
     * 消息编辑者
     */
    @ApiModelProperty("消息编辑者")
    private String xeditor;
    /**
     * 消息是否可变
     */
    @ApiModelProperty("消息是否可变")
    private Boolean xhasMobile;
    /**
     * 消息可变数据
     */
    @ApiModelProperty("消息可变数据")
    private String xmobileData;
    /**
     * 消息名称
     */
    @ApiModelProperty("消息名称")
    private String xname;
    /**
     * 消息特性
     */
    @ApiModelProperty("消息特性")
    private String xproperties;
}
