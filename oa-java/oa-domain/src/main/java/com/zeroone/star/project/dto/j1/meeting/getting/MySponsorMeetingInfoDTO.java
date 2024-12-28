package com.zeroone.star.project.dto.j1.meeting.getting;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.apache.ibatis.type.JdbcType;

import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.project.vo.j1.meeting.getting
 * @Author: dashuai
 * @CreateTime: 2024-10-21  00:06
 * @Description: 我发起的会议信息对应的领域模型VO
 * @Version: 1.0
 */
@Data
@ApiModel("我发起的会议信息传输数据对象")
public class MySponsorMeetingInfoDTO {
    /**
     * @description: 会议id
     **/
    /*@ApiModelProperty(value = "会议id", example = "1")
    private String xid ;*/

    /**
     * @description: 权重
     **/
    /*@ApiModelProperty(value = "权重", example = "1")
    private String xdistributeFactor;*/

    /**
     * @description: 会议实际结束时间
     **/
    /*@ApiModelProperty(value = "会议实际结束时间", example = "2024-10-21 00:06:00")
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime xactualCompletedTime;*/

    /**
     * @description: 会议实际开始时间
     **/
    /*@ApiModelProperty(value = "会议实际开始时间", example = "2024-10-21 00:06:00")
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime xactualStartTime;*/

    /**
     * @description: 会议申请人
     **/
    /*@ApiModelProperty(value = "会议申请人", example = "张三")
    private String xapplicant;*/

    /**
     * @description: 会议审核人
     **/
    /*@ApiModelProperty(value = "会议审核人", example = "李四")
    private String xauditor;*/

    /**
     * @description: 会议预计结束时间
     **/
    @ApiModelProperty(value = "会议预计结束时间", example = "2024-10-21 00:06:00")
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime xcompletedTime;

    /**
     * @description: 会议确认状态
     **/
    /*@ApiModelProperty(value = "会议确认状态", example = "allow")
    private String xconfirmStatus;*/

    /**
     * @description: 会议描述信息
     **/
    /*@ApiModelProperty(value = "会议描述信息", example = "会议描述信息")
    private String xdescription;*/

    /**
     * @description: 会议主持人
     **/
    /*@ApiModelProperty(value = "会议主持人", example = "王五")
    private String xhostPerson;*/

    /**
     * @description: 会议主持单位
     **/
    /*@ApiModelProperty(value = "会议主持单位", example = "01星球")
    private String xhostUnit;*/

    /**
     * @description: 是否手动完成会议
     **/
    /*@ApiModelProperty(value = "是否手动完成会议", example = "true")
    private boolean xmanualCompleted;*/

    /**
     * @description: 会议备注
     **/
    /*@ApiModelProperty(value = "会议备注", example = "会议备注")
    private String xmemo;*/

    /**
     * @description: 会议模式
     **/
    /*@ApiModelProperty(value = "会议模式", example = "1")
    private String xmode;*/

    /**
     * @description: 会议对应的拼音
     **/
    /*@ApiModelProperty(value = "会议对应的拼音", example = "huiyishijian")
    private String xpinyin;*/

    /**
     * @description: 会议对应的拼音首字母
     **/
    /*@ApiModelProperty(value = "会议对应的拼音首字母", example = "hysj")
    private String xpinyinInitial;*/

    /**
     * @description: 会议房间
     **/
    @ApiModelProperty(value = "会议房间", example = "会议室1")
    private String xroomName;

    /**
     * @description: 会议房间id
     **/
    /*@ApiModelProperty(value = "会议房间id", example = "1")
    private String xroomId;*/

    /**
     * @description: 会议链接
     **/
    /*@ApiModelProperty(value = "会议链接", example = "http://www.baidu.com")
    private String xroomLink;*/

    /**
     * @description: 会议预计开始时间
     **/
    @ApiModelProperty(value = "会议预计开始时间", example = "2024-10-21 00:06:00")
    @TableField(jdbcType = JdbcType.TIMESTAMP)
    private LocalDateTime xstartTime;

    /**
     * @description: 会议主题
     **/
    @ApiModelProperty(value = "会议主题", example = "会议主题")
    private String xsubject;

    /**
     * @description: 会议摘要
     **/
    /*@ApiModelProperty(value = "会议摘要", example = "会议摘要")
    private String xsummary;*/

    /**
     * @description: 会议类型
     **/
    /*@ApiModelProperty(value = "会议类型", example = "1")
    private String xtype;*/

    /**
     * @description: 会议房间地址
     **/
   /* @ApiModelProperty(value = "会议房间地址", example = "01星球6层会议室1")
    private String xbuilding;*/
}
