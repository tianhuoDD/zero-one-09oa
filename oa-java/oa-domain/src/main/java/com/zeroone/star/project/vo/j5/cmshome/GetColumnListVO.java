package com.zeroone.star.project.vo.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 描述：获取栏目类型响应实体类
 * </p>
 * @author 陈思蒙
 */
@Data
@ApiModel("获取栏目类型")
public class GetColumnListVO {

    @ApiModelProperty(value = "id")
    private String id;
    @ApiModelProperty(value = "栏目id")
    private String appId;
    @ApiModelProperty(value = "栏目名称")
    private String appName;
    @ApiModelProperty(value = "栏目类别")
    private String appType;
    @ApiModelProperty(value = "描述")
    private String description;
    @ApiModelProperty(value = "栏目图标")
    private String appIcon;
    @ApiModelProperty(value = "图标颜色")
    private String iconColor;
    @ApiModelProperty(value = "分类列表")
    private List<String> categoryName;
    @ApiModelProperty(value = "创建人")
    private String creatorPerson;
    @ApiModelProperty(value = "创建单元名称")
    private String creatorUnitName;
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;
    @ApiModelProperty(value = "更新时间")
    private LocalDateTime updateTime;
    @ApiModelProperty(value = "总结")
    private String summary;
    @ApiModelProperty(value = "标题")
    private List<String> title;
}
