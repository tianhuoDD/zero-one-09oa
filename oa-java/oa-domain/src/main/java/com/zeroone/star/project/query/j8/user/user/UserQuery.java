package com.zeroone.star.project.query.j8.user.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = false)
@Data
@ApiModel("用户查询对象")
public class UserQuery {

    @ApiModelProperty(value = "当前页码", example = "1")
    private int currentPage;

    @ApiModelProperty(value = "每页条数", example = "10")
    private int pageSize;

    @ApiModelProperty(value = "用户名", example = "张三")
    private String xname;

    @ApiModelProperty(value = "年龄最小值", example = "20")
    private Integer minAge;

    @ApiModelProperty(value = "年龄最大值", example = "40")
    private Integer maxAge;

    @ApiModelProperty(value = "性别", example = "M")
    private String xgenderType;

    @ApiModelProperty(value = "手机号", example = "1234567890")
    private String xmobile;

    @ApiModelProperty(value = "状态", example = "active")
    private String xstatus;

    @ApiModelProperty(value = "创建时间范围开始", example = "2023-01-01 00:00:00")
    private String createTimeStart;

    @ApiModelProperty(value = "创建时间范围结束", example = "2023-12-31 23:59:59")
    private String createTimeEnd;

    @ApiModelProperty(value = "更新时间范围开始", example = "2023-01-01 00:00:00")
    private String updateTimeStart;

    @ApiModelProperty(value = "更新时间范围结束", example = "2023-12-31 23:59:59")
    private String updateTimeEnd;
}
