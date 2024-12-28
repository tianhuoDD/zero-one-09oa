package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("日历信息传输对象")
public class CalendarInfoDTO {
    private String xid;
    /**
     * 日历名称
     */
    @ApiModelProperty(value = "日历名称",example ="王小华的日历")
    private String xname;
    /**
     * 颜色
     */
    @ApiModelProperty(value = "日历颜色",example ="蓝色")
    private String xcolor;
    /**
     * 类型
     */
    @ApiModelProperty(value = "日历类型",example ="")
    private String xtype;
    /**
     * 是否公开
     */
    @ApiModelProperty(value = "是否公开",example ="是")
    private Boolean xisPublic;
    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example ="")
    private String xdescription;
    /**
     * 所属组织
     */
    @ApiModelProperty(value = "所属组织",example ="图灵院")
    private String xdistributeFactor;
    /**
     * 管理者
     */
    @ApiModelProperty(value = "管理者",example ="王小华")
    private String xcreateor;
    /**
     * 可见范围
     */
    @ApiModelProperty(value = "可见范围",example ="王小华")
    private List<String> xviewAbleList;
    /**
     * 可新建范围
     */
    @ApiModelProperty(value = "可新建范围",example ="王小华")
    private List<String> xmanageAbleList;
    /**
     * 是否启用
     */
    @ApiModelProperty(value = "是否启用",example ="是")
    private String xstatus;
}
