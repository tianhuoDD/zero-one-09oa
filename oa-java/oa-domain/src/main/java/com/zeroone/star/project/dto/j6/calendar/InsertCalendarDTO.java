package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * ClassName: CreateCalendarDTO
 * Description:
 *
 * @Author llw
 * @Create 2024/10/19 21:44
 * @Version 1.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("新增日历请求数据")
public class InsertCalendarDTO {

    @ApiModelProperty(value = "日历名称", required = true, example = "工作日历")
    private String xname;

    @ApiModelProperty(value = "颜色", example = "#FFFFFF")
    private String xcolor;

    @ApiModelProperty(value = "日历类型(PERSON/UNIT)", example = "UNIT")
    private String xtype;

    @ApiModelProperty(value = "是否公开(true,false)", example = "true")
    private Boolean xisPublic;

    @ApiModelProperty(value = "备注", example = "这是一个备注")
    private String xdescription;

    @ApiModelProperty(value = "是否启用(OPEN/CLOSE)", example = "OPEN")
    private String xstatus;

    @ApiModelProperty(value = "所属组织ID", example = "3bac637a-b1d6-43d7-8c93-92850c380aa9")
    private String organization; // 单选字段

    @ApiModelProperty(value = "管理者ID列表", example = "[\"e984c6cb-818d-485d-9988-5b1707b6304e\"]")
    private List<String> managers; // 多选字段

    @ApiModelProperty(value = "可见范围ID列表", example = "[\"d3967106-954b-4cb3-8fdf-19210f73b95b\", \"3bac637a-b1d6-43d7-8c93-92850c380aa9\", \"adf8f4fb-7b29-4f0b-be73-da0d0c398846\"]")
    private List<String> viewableRange; // 多选字段

    @ApiModelProperty(value = "可新建范围ID列表", example = "[\"51b554e4-92bc-48cd-b3f1-2cb930f8be39\", \"ef862c1d-8428-4cee-a522-14c6f3f8bb42\"]")
    private List<String> manageableRange; // 多选字段
}