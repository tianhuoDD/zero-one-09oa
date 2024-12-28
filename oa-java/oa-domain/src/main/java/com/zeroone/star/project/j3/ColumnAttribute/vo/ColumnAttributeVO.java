package com.zeroone.star.project.j3.ColumnAttribute.vo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.List;

/**
 * CMS表单视图对象
 *
 * 该类表示CMS系统中的表单信息的视图对象。
 *
 * @author lenyan
 * @since 2024-10-15
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel(description = "CMS表单视图对象")
public class ColumnAttributeVO implements Serializable {

    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "栏目唯一标识", example = "01d4245f-a8e8-4b98-a969-efaa32af674b")
    private String xid;

    @ApiModelProperty(value = "栏目创建时间", example = "2024-10-17 21:15:51")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "栏目序列号", example = "2024101721155001d4245f-a8e8-4b98-a969-efaa32af674b")
    private String xsequence;

    @ApiModelProperty(value = "栏目最近更新时间", example = "2024-10-18 15:23:46")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "栏目分布因子", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "是否所有人可发布", example = "1")
    private Boolean xallPeoplePublish;

    @ApiModelProperty(value = "是否所有人可见", example = "1")
    private Boolean xallPeopleView;

    @ApiModelProperty(value = "是否允许匿名", example = "1")
    private Boolean xanonymousAble;

    @ApiModelProperty(value = "栏目别名", example = "事例栏目的别名")
    private String xappAlias;

    @ApiModelProperty(value = "栏目图标", example = "null")
    private String xappIcon;

    @ApiModelProperty(value = "栏目排序", example = "123")
    private String xappInfoSeq;

    @ApiModelProperty(value = "栏目备忘录", example = "这是备忘录")
    private String xappMemo;

    @ApiModelProperty(value = "栏目名称", example = "事例栏目")
    private String xappName;

    @ApiModelProperty(value = "栏目类型", example = "展示栏目")
    private String xappType;

    @ApiModelProperty(value = "栏目创建者身份", example = "xadmin")
    private String xcreatorIdentity;

    @ApiModelProperty(value = "栏目创建者", example = "xadmin")
    private String xcreatorPerson;

    @ApiModelProperty(value = "栏目创建者顶部单位名称", example = "xadmin")
    private String xcreatorTopUnitName;

    @ApiModelProperty(value = "栏目创建者单位名称", example = "xadmin")
    private String xcreatorUnitName;

    @ApiModelProperty(value = "默认编辑表单标识", example = "9f7e2470-24cd-4766-beae-5b8f0d45522f")
    private String xdefaultEditForm;

    @ApiModelProperty(value = "默认阅读表单标识", example = "b10599c7-4933-4b3b-b345-bcb548cf61a6")
    private String xdefaultReadForm;

    @ApiModelProperty(value = "栏目描述", example = "这是栏目的描述捏")
    private String xdescription;

    @ApiModelProperty(value = "文档类型", example = "信息")
    private String xdocumentType;

    @ApiModelProperty(value = "栏目图标颜色", example = "null")
    private String xiconColor;

    @ApiModelProperty(value = "是否发送通知", example = "1")
    private Boolean xsendNotify;

    @ApiModelProperty(value = "忽略标题",example = "true")
    private Boolean ignoreTitle;

    @ApiModelProperty(value = "检查草稿",example = "true")
    private Boolean latest;

    @ApiModelProperty(value = "栏目视图",example = "true")
    private Boolean xshowAllDocuments;

    @ApiModelProperty(value = "自动保存",example = "true")
    private Boolean saveDraftOnClose;

    @ApiModelProperty(value = "可见范围",example = "可见范围")
    private List<String> xviewablePersonList;

    @ApiModelProperty(value = "发布者",example = "发布者")
    private List<String> xpublishablePersonList;

    @ApiModelProperty(value = "管理者",example = "管理者")
    private List<String> xmanageablePersonList;
}
