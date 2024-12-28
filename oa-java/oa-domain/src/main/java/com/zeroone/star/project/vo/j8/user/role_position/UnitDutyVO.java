package com.zeroone.star.project.vo.j8.user.role_position;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.time.LocalDateTime;
import lombok.Data;

@Data
@ApiModel(description = "职务信息")
public class UnitDutyVO {

    @ApiModelProperty(value = "主键ID", required = true, example = "123e4567-e89b-12d3-a456-426614174000")
    private String xid;

    @ApiModelProperty(value = "创建时间", example = "2024-10-21T10:09:51")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "序列号", example = "ABC123")
    private String xsequence;

    @ApiModelProperty(value = "更新时间", example = "2024-10-21T12:00:00")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分配因子", example = "5")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "描述信息", example = "这是一个测试描述")
    private String xdescription;

    @ApiModelProperty(value = "唯一名称（带标识符）", example = "董事@123e4567-e89b-12d3-a456-426614174000@UD")
    private String xdistinguishedName;

    @ApiModelProperty(value = "职务名称", example = "董事")
    private String xname;

    @ApiModelProperty(value = "排序号", example = "214740591")
    private Integer xorderNumber;

    @ApiModelProperty(value = "拼音", example = "dongshi")
    private String xpinyin;

    @ApiModelProperty(value = "拼音首字母", example = "ds")
    private String xpinyinInitial;

    @ApiModelProperty(value = "唯一标识", example = "6e99b8f8-0821-46f8-8426-86a4f64f20ec")
    private String xunique;

    @ApiModelProperty(value = "所属组织ID", example = "7dc8b0fe-22c1-4855-ae0f-422ce7481ba3")
    private String xunit;
}
