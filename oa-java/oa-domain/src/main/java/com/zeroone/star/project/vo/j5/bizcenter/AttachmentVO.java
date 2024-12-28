package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("附件信息")
public class AttachmentVO {


    @Alias("xid")
    @ApiModelProperty("ID")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @Alias("xsequence")
    @ApiModelProperty("序列")
    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;

    @Alias("xdistributeFactor")
    @ApiModelProperty("分配因子")
    private Integer distributeFactor;

    @Alias("xencryptKey")
    @ApiModelProperty("加密密钥")
    private String encryptKey;

    @Alias("xactivity")
    @ApiModelProperty("活动")
    private String activity;

    @Alias("xactivityName")
    @ApiModelProperty("活动名称")
    private String activityName;

    @Alias("xactivityToken")
    @ApiModelProperty("活动令牌")
    private String activityToken;

    @Alias("xactivityType")
    @ApiModelProperty("活动类型")
    private String activityType;

    @Alias("xapplication")
    @ApiModelProperty("应用程序")
    private String application;

    @Alias("xcompleted")
    @ApiModelProperty("是否完成")
    private Boolean completed;

    @Alias("xdeepPath")
    @ApiModelProperty("深度路径")
    private Boolean deepPath;

    @Alias("xextension")
    @ApiModelProperty("扩展")
    private String extension;

    @Alias("xfromId")
    @ApiModelProperty("来源ID")
    private String fromId;

    @Alias("xfromJob")
    @ApiModelProperty("来源工作")
    private String fromJob;

    @Alias("xfromPath")
    @ApiModelProperty("来源路径")
    private String fromPath;

    @Alias("xjob")
    @ApiModelProperty("工作")
    private String job;

    @Alias("xlastUpdatePerson")
    @ApiModelProperty("最后更新人")
    private String lastUpdatePerson;

    @Alias("xlastUpdateTime")
    @ApiModelProperty("最后更新时间")
    private LocalDateTime lastUpdateTime;

    @Alias("xlength")
    @ApiModelProperty("长度")
    private Long length;

    @Alias("xname")
    @ApiModelProperty("名称")
    private String name;

    @Alias("xobjectSecurityClearance")
    @ApiModelProperty("对象安全等级")
    private Integer objectSecurityClearance;

    @Alias("xorderNumber")
    @ApiModelProperty("订单编号")
    private Integer orderNumber;

    @Alias("xperson")
    @ApiModelProperty("人员")
    private String person;

    @Alias("xprocess")
    @ApiModelProperty("流程")
    private String process;

    @Alias("xproperties")
    @ApiModelProperty("属性")
    private String properties;

    @Alias("xsite")
    @ApiModelProperty("站点")
    private String site;

    @Alias("xstorage")
    @ApiModelProperty("存储")
    private String storage;

    @Alias("xstringValue01")
    @ApiModelProperty("字符串值01")
    private String stringValue01;

    @Alias("xstringValue02")
    @ApiModelProperty("字符串值02")
    private String stringValue02;

    @Alias("xstringValue03")
    @ApiModelProperty("字符串值03")
    private String stringValue03;

    @Alias("xtext")
    @ApiModelProperty("文本")
    private String text;

    @Alias("xtype")
    @ApiModelProperty("类型")
    private String type;

    @Alias("xwork")
    @ApiModelProperty("工作")
    private String work;

    @Alias("xworkCompleted")
    @ApiModelProperty("工作完成")
    private String workCompleted;

    @Alias("xworkCreateTime")
    @ApiModelProperty("工作创建时间")
    private LocalDateTime workCreateTime;

    private List<String> controllerIdentityList;

    private List<String> controllerUnitList;

    private List<String> divisionList;

    private List<String> editidentityList;

    private List<String> editunitList;

    private List<String> readIdentityList;

    private List<String> readUnitList;

}
