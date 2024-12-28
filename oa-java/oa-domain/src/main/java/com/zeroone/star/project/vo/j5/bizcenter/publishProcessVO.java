package com.zeroone.star.project.vo.j5.bizcenter;

import com.zeroone.star.project.dto.j5.bizcenter.ProcessCategoryDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;
import java.util.List;


@Data
@Builder
@ApiModel("公共流程对象")
@NoArgsConstructor
@AllArgsConstructor
public class publishProcessVO {
    @ApiModelProperty("流程分类列表")
    private List<ProcessCategoryDTO> wrapOutCategoryListList;

    @ApiModelProperty("日期")
    private LocalDateTime date;

    @ApiModelProperty("ID")
    private String id;

    @ApiModelProperty("应用名称")
    private String appName;

    @ApiModelProperty("应用别名")
    private String appAlias;

    @ApiModelProperty("应用类型")
    private String appType;

    @ApiModelProperty("文档类型")
    private String documentType;

    @ApiModelProperty("应用信息序列")
    private String appInfoSeq;

    @ApiModelProperty("应用图标")
    private String appIcon;

    @ApiModelProperty("图标颜色")
    private String iconColor;

    @ApiModelProperty("创建人")
    private String creatorPerson;

    @ApiModelProperty("创建人身份")
    private String creatorIdentify;

    @ApiModelProperty("创建人单位名称")
    private String creatorUnitName;

    @ApiModelProperty("创建人顶级单位名称")
    private String creatorTopUnitName;

    @ApiModelProperty("是否允许匿名")
    private Boolean anonymousAble;

    @ApiModelProperty("是否所有人可查看")
    private Boolean allPeopleView;

    @ApiModelProperty("是否所有人可发布")
    private Boolean allPeoplePublish;

    @ApiModelProperty("是否发送通知")
    private Boolean sendNotify;

    @ApiModelProperty("是否显示所有文档")
    private Boolean showAllDocument;

//    @ApiModelProperty("是否允许待发布")
//    private boolean allowWaitPublish;

    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;
}
