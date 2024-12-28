package com.zeroone.star.project.dto.j5.cmshome;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;
import java.util.List;

/**
 * 发布消息对象
 * @author wxf
 */
@Data
@ApiModel("发布消息对象")
public class PublishMessageDTO {

    @ApiModelProperty(value = "应用别名", example = "新闻")
    private String xappAlias;

    @ApiModelProperty(value = "应用ID", example = "471c81a5-2e8b-4fbc-884f-5f85697fe6fc")
    private String xappId;

    @ApiModelProperty(value = "应用名称", example = "新闻")
    private String xappName;

    @ApiModelProperty(value = "作者组列表", example = "[]")
    private List<String> xauthorGroupList;

    @ApiModelProperty(value = "作者列表", example = "[]")
    private List<String> xauthorList;

    @ApiModelProperty(value = "作者人员列表", example = "[\"001@P\"]")
    private List<String> xauthorPersonList;

    @ApiModelProperty(value = "作者单位列表", example = "[]")
    private List<String> xauthorUnitList;

    @ApiModelProperty(value = "类别别名", example = "新闻-你好")
    private String xcategoryAlias;

    @ApiModelProperty(value = "类别ID", example = "22db7c1a-f833-4f0b-804f-814df4bf7341")
    private String xcategoryId;

    @ApiModelProperty(value = "类别名称", example = "新闻")
    private String xcategoryName;

    @ApiModelProperty(value = "推荐次数", example = "0")
    private int xcommendCount;

    @ApiModelProperty(value = "评论次数", example = "0")
    private int xcommentCount;

    @ApiModelProperty(value = "创建时间", example = "2024-11-04T17:29:07")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "创建人身份", example = "开发员工@002_001@I")
    private String xcreatorIdentity;

    @ApiModelProperty(value = "创建人", example = "开发员工@001@P")
    private String xcreatorPerson;

    @ApiModelProperty(value = "创建人顶级单位名称", example = "开发部@002@U")
    private String xcreatorTopUnitName;

    @ApiModelProperty(value = "创建人单位名称", example = "开发部@002@U")
    private String xcreatorUnitName;

    @JsonProperty("xdocData")
    @ApiModelProperty(value = "文档数据", example = "{\"attachmentList\": []}")
    private DocData xdocData;

    @ApiModelProperty(value = "文档状态", example = "published")
    private String xdocStatus;

    @ApiModelProperty(value = "文档类型", example = "信息")
    private String xdocumentType;

    @ApiModelProperty(value = "表单ID", example = "166f8aa1-a733-4012-b94a-f0f8cc08d09b")
    private String xform;

    @ApiModelProperty(value = "表单名称", example = "发布类编辑表单")
    private String xformName;

    @ApiModelProperty(value = "是否有索引图片", example = "false")
    private boolean xhasIndexPic;

    @ApiModelProperty(value = "文档ID", example = "d7a5521d-4ab9-413a-8e5a-cb1d669c19be")
    private String xid;

    @ApiModelProperty(value = "是否全部阅读", example = "true")
    private boolean xisAllRead;

    @ApiModelProperty(value = "是否置顶", example = "false")
    private boolean xisTop;

    @ApiModelProperty(value = "管理人员列表", example = "[\"001@P\"]")
    private List<String> xmanagerList;

    @ApiModelProperty(value = "修改时间", example = "2024-11-04T17:29:29")
    private LocalDateTime xmodifyTime;

    @ApiModelProperty(value = "图片列表", example = "[]")
    private List<String> xpictureList;

    @ApiModelProperty(value = "发布时间", example = "2024-11-04T17:29:29")
    private LocalDateTime xpublishTime;

    @ApiModelProperty(value = "阅读表单ID", example = "dd38e6bf-ab43-49ea-82dc-ed7fce2325ab")
    private String xreadFormId;

    @ApiModelProperty(value = "阅读表单名称", example = "发布类阅读表单")
    private String xreadFormName;

    @ApiModelProperty(value = "阅读组列表", example = "[]")
    private List<String> xreadGroupList;

    @ApiModelProperty(value = "阅读人员列表", example = "[\"所有人\", \"001@P\"]")
    private List<String> xreadPersonList;

    @ApiModelProperty(value = "阅读单位列表", example = "[]")
    private List<String> xreadUnitList;

    @ApiModelProperty(value = "是否已审核", example = "true")
    private boolean xreviewed;

    @ApiModelProperty(value = "序列号", example = "20241104172906d7a5521d-4ab9-413a-8e5a-cb1d669c19be")
    private String xsequence;

    @ApiModelProperty(value = "序列应用别名", example = "新闻")
    private String xsequenceAppAlias;

    @ApiModelProperty(value = "序列类别别名", example = "新闻-你好")
    private String xsequenceCategoryAlias;

    @ApiModelProperty(value = "序列创建人", example = "开发员工@001@P")
    private String xsequenceCreatorPerson;

    @ApiModelProperty(value = "序列创建单位名称", example = "开发部@002@U")
    private String xsequenceCreatorUnitName;

    @ApiModelProperty(value = "序列标题", example = "cgd7a5521d-4ab9-413a-8e5a-cb1d669c19be")
    private String xsequenceTitle;

    @ApiModelProperty(value = "摘要", example = "老八")
    private String xsummary;

    @ApiModelProperty(value = "标题", example = "cg")
    private String xtitle;

    @ApiModelProperty(value = "更新时间", example = "2024-11-04T17:29:42")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "浏览次数", example = "1")
    private int xviewCount;

    @Data
    public static class DocData {
        @ApiModelProperty(value = "附件列表", example = "[]")
        private List<String> attachmentList;


        @ApiModelProperty(value = "说明", example = "曹高")
        private String explain;

        @ApiModelProperty(value = "富文本编辑器内容", example = "<p>老八</p>")
        private String htmleditor;

        @ApiModelProperty(value = "图像剪切信息", example = "")
        private String imageclipper;

        @ApiModelProperty(value = "是否为新文档", example = "false")
        private boolean isNew;

        @ApiModelProperty(value = "发布者信息", example = "[]")
        private List<String> publishFor;

        @ApiModelProperty(value = "主题", example = "cg")
        private String subject;

        @ApiModelProperty(value = "云图片列表", example = "[]")
        private List<String> cloudPictures;
    }
}
