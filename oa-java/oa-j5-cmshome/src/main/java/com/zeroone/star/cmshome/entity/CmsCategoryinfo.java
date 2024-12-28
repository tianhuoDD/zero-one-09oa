package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-25
 */
@Getter
@Setter
@TableName("cms_categoryinfo")
public class CmsCategoryinfo implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    @ApiModelProperty(value = "ID")
    @TableField(value = "xid")
    private String xid;

    @ApiModelProperty(value = "栏目名称")
    @TableField(value = "xcategoryName")
    private String xcategoryName;

    @ApiModelProperty(value = "应用ID")
    @TableField(value = "xappId")
    private String xappId;

    @ApiModelProperty(value = "应用名称")
    @TableField(value = "xappName")
    private String xappName;

    @ApiModelProperty(value = "文档类型")
    @TableField(value = "xdocumentType")
    private String xdocumentType;

    @ApiModelProperty(value = "栏目别名")
    @TableField(value = "xcategoryAlias")
    private String xcategoryAlias;

    @ApiModelProperty(value = "工作流类型")
    @TableField(value = "xworkflowType")
    private String xworkflowType;

    @ApiModelProperty(value = "表单ID")
    @TableField(value = "xformId")
    private String xformId;

    @ApiModelProperty(value = "表单名称")
    @TableField(value = "xformName")
    private String xformName;

    @ApiModelProperty(value = "阅读表单ID")
    @TableField(value = "xreadFormId")
    private String xreadFormId;

    @ApiModelProperty(value = "阅读表单名称")
    @TableField(value = "xreadFormName")
    private String xreadFormName;

    @ApiModelProperty(value = "栏目序号")
    @TableField(value = "xcategorySeq")
    private String xcategorySeq;

    @ApiModelProperty(value = "创建人")
    @TableField(value = "xcreatorPerson")
    private String xcreatorPerson;

    @ApiModelProperty(value = "创建者身份")
    @TableField(value = "xcreatorIdentity")
    private String xcreatorIdentity;

    @ApiModelProperty(value = "创建者单位名称")
    @TableField(value = "xcreatorUnitName")
    private String xcreatorUnitName;

    @ApiModelProperty(value = "创建者顶级单位名称")
    @TableField(value = "xcreatorTopUnitName")
    private String xcreatorTopUnitName;

    @ApiModelProperty(value = "是否所有人可查看")
    @TableField(value = "xallPeopleView")
    private Boolean xallPeopleView;

    @ApiModelProperty(value = "是否所有人可发布")
    @TableField(value = "xallPeoplePublish")
    private Boolean xallPeoplePublish;

    @ApiModelProperty(value = "是否允许匿名访问")
    @TableField(value = "xanonymousAble")
    private Boolean xanonymousAble;

    @ApiModelProperty(value = "是否发送通知")
    @TableField(value = "xsendNotify")
    private Boolean xsendNotify;

    @ApiModelProperty(value = "是否空白时通知所有人")
    @TableField(value = "xblankToAllNotify")
    private Boolean xblankToAllNotify;

    @ApiModelProperty(value = "创建时间")
    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "更新时间")
    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;

}
