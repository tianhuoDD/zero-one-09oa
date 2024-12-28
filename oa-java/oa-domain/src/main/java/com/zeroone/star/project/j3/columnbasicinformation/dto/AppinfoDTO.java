package com.zeroone.star.project.j3.columnbasicinformation.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import java.time.LocalDateTime;

/**
 * 描述：栏目传输对象
 * @author Kokoro
 * @version 1.0.0
 */
@Data
@ApiModel("栏目传输对象")
public class AppinfoDTO {

    @ApiModelProperty(value = "栏目唯一标识", example = "")
    private String xid;

    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "栏目创建时间", example = "2024-10-17 21:15:51")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "栏目序列号", example = "2024101721155001d4245f-a8e8-4b98-a969-efaa32af674b")
    private String xsequence;

    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "栏目最近更新时间", example = "2024-10-18 15:23:46")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "栏目分布因子， 默认为空", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "是否所有人可发布", example = "1")
    private Boolean xallPeoplePublish;

    @ApiModelProperty(value = "是否所有人可见", example = "1")
    private Boolean xallPeopleView;

    @ApiModelProperty(value = "是否显示所有文档视图", example = "0")
    private Boolean xshowAllDocuments;

    @ApiModelProperty(value = "是否允许匿名", example = "1")
    private Boolean xanonymousAble;

    @ApiModelProperty(value = "栏目别名", example = "事例栏目的别名")
    private String xappAlias;

    @ApiModelProperty(value = "栏目图标，默认为空", example = "")
    private String xappIcon;

    @Min(value = 0, message = "最小值不能小于0")
    @Max(value = 999, message = "最大值不能大于999")
    @ApiModelProperty(value = "栏目排序", example = "123")
    private String xappInfoSeq;

    @ApiModelProperty(value = "栏目备忘录", example = "这是备忘录")
    private String xappMemo;

    @ApiModelProperty(value = "栏目名称", example = "")
    private String xappName;

    @ApiModelProperty(value = "栏目类型", example = "")
    private String xappType;

    @ApiModelProperty(value = "栏目创建者身份", example = "xadmin")
    private String xcreatorIdentity;

    @ApiModelProperty(value = "栏目创建者", example = "xadmin")
    private String xcreatorPerson;

    @ApiModelProperty(value = "栏目创建者顶部单位名称", example = "xadmin")
    private String xcreatorTopUnitName;

    @ApiModelProperty(value = "栏目创建者单位名称", example = "xadmin")
    private String xcreatorUnitName;

    @ApiModelProperty(value = "默认编辑表单标识id", example = "5f188b1d-de67-4786-bb0b-b332af720de4")
    private String xdefaultEditForm;

    @ApiModelProperty(value = "默认阅读表单标识id", example = "00706d34-67d0-4517-87dd-31d910c2e9d2")
    private String xdefaultReadForm;

    @ApiModelProperty(value = "栏目描述", example = "这是栏目的描述捏")
    private String xdescription;

    @ApiModelProperty(value = "文档类型", example = "信息")
    private String xdocumentType;

    @ApiModelProperty(value = "栏目图标颜色,默认为空", example = "")
    private String xiconColor;

    @ApiModelProperty(value = "是否发送通知", example = "1")
    private Boolean xsendNotify;
}
