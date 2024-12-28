package com.zeroone.star.project.vo.j8.user.role_position;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.List;
import lombok.Data;

@Data
@ApiModel(description = "组织单元信息")
public class UnitVO {

    @ApiModelProperty(value = "组织ID", example = "7dc8b0fe-22c1-4855-ae0f-422ce7481ba3")
    private String id;

    @ApiModelProperty(value = "组织名称", example = "测试组织")
    private String name;

    @ApiModelProperty(value = "组织唯一标识", example = "12312123123")
    private String unique;

    @ApiModelProperty(value = "组织全称（带标识符）", example = "测试组织@12312123123@U")
    private String distinguishedName;

    @ApiModelProperty(value = "组织类型列表", example = "[\"company\"]")
    private List<String> typeList;

    @ApiModelProperty(value = "组织拼音", example = "ceshizuzhi")
    private String pinyin;

    @ApiModelProperty(value = "组织拼音首字母", example = "cszz")
    private String pinyinInitial;

    @ApiModelProperty(value = "组织描述", example = "1231323")
    private String description;

    @ApiModelProperty(value = "组织简称", example = "123132")
    private String shortName;

    @ApiModelProperty(value = "组织层级", example = "1")
    private int level;

    @ApiModelProperty(value = "层级名称", example = "测试组织")
    private String levelName;

    @ApiModelProperty(value = "层级顺序号", example = "0000000000")
    private String levelOrderNumber;

    @ApiModelProperty(value = "上级组织ID", example = "")
    private String superior;

    @ApiModelProperty(value = "组织排序号", example = "214740446")
    private int orderNumber;

    @ApiModelProperty(value = "组织控制者列表", example = "[]")
    private List<String> controllerList;

    @ApiModelProperty(value = "创建时间", example = "2024-10-21 10:07:26")
    private String createTime;

    @ApiModelProperty(value = "更新时间", example = "2024-10-21 10:07:26")
    private String updateTime;
}
