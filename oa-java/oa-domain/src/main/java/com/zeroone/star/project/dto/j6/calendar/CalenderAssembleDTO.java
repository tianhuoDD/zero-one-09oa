package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@ApiModel
@Data
public class CalenderAssembleDTO {
    @ApiModelProperty(value = "每页大小", example = "10")
    /**
     * 分页查询大小
     */
    private int size;
    /**
     * 分页查询页码
     */
    @ApiModelProperty(value = "页码", example = "1")
    private int page;
    /**
     * 日历id
     */
    @ApiModelProperty(value = "日历ID", example = "0acca8db-e359-4ae7-a728-c94dd1925b7b")
    private String id;
    @ApiModelProperty(value = "日历名称", example = "王五的日历")
    private String name;
    @ApiModelProperty(value = "日历类型", example = "PERSON")
    private String type;
    @ApiModelProperty(value = "目标用户或组", example = "xadmin")
    private String target;
    @ApiModelProperty(value = "日历颜色", example = "#9072f1")
    private String color;
    @ApiModelProperty(value = "日历描述", example = "423432")
    private String description;
    @ApiModelProperty(value = "日历来源", example = "PERSON")
    private String source;
    @ApiModelProperty(value = "日历创建者", example = "xadmin")
    private String createor;
    @ApiModelProperty(value = "是否公开", example = "true")
    private boolean isPublic;
    @ApiModelProperty(value = "是否可管理", example = "true")
    private boolean manageable;
    @ApiModelProperty(value = "是否可发布", example = "true")
    private boolean publishable;
    @ApiModelProperty(value = "是否已关注", example = "false")
    private boolean followed;
    @ApiModelProperty(value = "可管理的人员列表")
    private List<String> manageablePersonList;
    @ApiModelProperty(value = "关注者列表")
    private List<String> followers;
    @ApiModelProperty(value = "可查看的人员列表")
    private List<String> viewablePersonList;
    @ApiModelProperty(value = "可查看的单位列表")
    private List<String> viewableUnitList;
    @ApiModelProperty(value = "可查看的组列表")
    private List<String> viewableGroupList;
    @ApiModelProperty(value = "可发布事件的人员列表")
    private List<String> publishablePersonList;
    @ApiModelProperty(value = "可发布事件的单位列表")
    private List<String> publishableUnitList;
    @ApiModelProperty(value = "可发布事件的组列表")
    private List<String> publishableGroupList;
    @ApiModelProperty(value = "日历状态", example = "OPEN")
    private String status;
    @ApiModelProperty(value = "创建时间", example = "2024-10-17 10:13:20")
    private String createTime;
    @ApiModelProperty(value = "更新时间", example = "2024-10-17 10:13:20")
    private String updateTime;
    @ApiModelProperty(value = "序列编号", example = "202410171013200acca8db-e359-4ae7-a728-c94dd1925b7b")
    private String sequence;
}