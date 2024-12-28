package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@ApiModel
@Data
public class CalendarDTO {




    @ApiModelProperty(value = "日历id", example = "succeed")

    private String xid;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2024-10-21 23:59:59")

    private Date xcreateTime;
    /**
     * 排序字段
     */
    @ApiModelProperty(value = "排序字段", example = "succeed")

    private String xsequence;
    /**
     * 更新时间
     */
    @ApiModelProperty(value = "更新时间", example = "2024-10-21 23:59:59")

    private Date xupdateTime;
    /**
     * 分发因子
     */
    @ApiModelProperty(value = "分发因子", example = "2")

    private int xdistributeFactor;
    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人", example = "张三")

    private String xcreateor;
    /**
     * 描述
     */
    @ApiModelProperty(value = "日历描述", example = "这是一个xxx日历")

    private String xdescription;
    /**
     * 是否公开
     */
    @ApiModelProperty(value = "是否公开", example = "true")

    private boolean xisPublic;
    /**
     * 对应人名称
     */
    @ApiModelProperty(value = "对应人名称", example = "李四")

    private String xname;
    /**
     * 来源
     */
    @ApiModelProperty(value = "操作日历id", example = "暂时不清楚")

    private String xsource;
    /**
     * 状态
     */
    @ApiModelProperty(value = "状态", example = "启用/关闭")

    private String xstatus;
    /**
     * 目标日历？暂时不清楚
     */
    @ApiModelProperty(value = "目标日历id", example = "暂时不清楚")

    private String xtarget;
    /**
     * 类型
     */
    @ApiModelProperty(value = "类型", example = "PERSONAL| LEADER | UNIT | MEETING | BUSINESS_TRIP | HOLIDAY\"")

    private String xtype;
@ApiModelProperty(value = "颜色", example = "#9072f1")
    /**
     * 颜色字段
     */
    private   String xcolor;
    /**
     * 新增是否关注的状态
     */
    @ApiModelProperty(value = "关注状态",example = "true")
    private  boolean followed;

}
