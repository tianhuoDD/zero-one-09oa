package com.zeroone.star.project.vo.j8.user.role_position;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.time.LocalDateTime;
import lombok.Data;

@Data
@ApiModel(description = "角色信息展示对象")
public class RoleVO {

    @ApiModelProperty(value = "角色ID", required = true, example = "123e4567-e89b-12d3-a456-426614174000")
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

    @ApiModelProperty(value = "唯一标识名称", example = "管理员@123e4567-e89b-12d3-a456-426614174000@UD")
    private String xdistinguishedName;

    @ApiModelProperty(value = "角色名称", example = "管理员")
    private String xname;

    @ApiModelProperty(value = "排序号", example = "214740591")
    private Integer xorderNumber;

    @ApiModelProperty(value = "拼音", example = "guanliyuan")
    private String xpinyin;

    @ApiModelProperty(value = "拼音首字母", example = "gly")
    private String xpinyinInitial;

    @ApiModelProperty(value = "唯一标识", example = "123e4567-e89b-12d3-a456-426614174000")
    private String xunique;

}
