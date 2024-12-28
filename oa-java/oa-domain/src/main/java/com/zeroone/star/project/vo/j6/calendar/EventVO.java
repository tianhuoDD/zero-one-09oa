package com.zeroone.star.project.vo.j6.calendar;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;
@Data
@ApiModel("日历日程对象")
public class EventVO {
    /**
     *日程Id唯一标识
     */
    @ApiModelProperty(value = "唯一标识",example ="123124514" )
    private String xid;

    /**
     *日程创建时间
     */
    @ApiModelProperty(value = "日程创建时间",example ="2024-10-20 17:23:00" )
    private Date xcreateTime;
    /**
     *通过时间生成的标识
     */
    @ApiModelProperty(value = "通过时间生成的标识",example ="202410201723001a13f8d2-394b-43bf-82aa-71d3d5e5098c" )
    private String xsequence;
    /**
     *日程更新时间
     */
    @ApiModelProperty(value = "日程更新时间",example ="2024-10-20 17:23:00" )
    private Date xupdateTime;
//    /**
//     *暂时不知道
//     *
//      可为null
    @ApiModelProperty(value = "",example ="" )
  private int xdistributeFactor;
    /**
     *是否提醒
     */
    @ApiModelProperty(value = "是否提醒",example ="1" )
    private boolean xalarm;
    /**
     *是否已经提醒过了
     */
    @ApiModelProperty(value = "是否已经提醒过了",example ="0" )
    private boolean xalarmAlready;
    /**
     *当前日程提醒时间
     */
    @ApiModelProperty(value = "当前日程提醒时间",example ="2024-12-19 23:55:00" )
    private Date xalarmTime;
    /**
     *绑定来源数据标识 （暂时不知道，需要进一步了解）
     */
    @ApiModelProperty(value = "绑定来源数据标识",example ="" )
    private String xbundle;
    /**
     *当前日程对应的日历唯一标识id
     */
    @ApiModelProperty(value = "当前日程对应的日历唯一标识id",example ="eb5e2b97-5601-4c37-b890-4d8ffa7849d4" )
    private String xcalendarId;
    /**
     * 日程显示在日历上的颜色
     */
    @ApiModelProperty(value = "日程显示在日历上的颜色",example ="#1462be" )
    private String xcolor;
    /**
     * 日程中备注信息，（文本框的内容 <p></p>）
     */
    @ApiModelProperty(value = "日程中备注信息",example =" <p>21312312</p>" )
    private String xcomment;
    /**
     * 日程中备注信息id （备注信息超过一定的大小，需要单独存储）
     */
    @ApiModelProperty(value = "日程中备注信息id",example =" " )
    private String xcommentId;
    /**
     * 日程创建人
     */
    @ApiModelProperty(value = "日程创建人",example ="xadmin" )
    private String xcreatePerson;
    /**
     *日程持续天数
     */
    @ApiModelProperty(value = "日程持续天数",example ="1" )
    private int xdaysOfDuration;
    /**
     * 日程结束时间
     */
    @ApiModelProperty(value = "日程结束时间",example ="2024-12-20 23:59:59" )
    private Date xendTime;
    /**
     *日程结束时间(暂时不知道与上面的区别)
     */
    @ApiModelProperty(value = "日程结束时间",example ="2024-12-20 23:59:59" )
    private String xendTimeStr;
    /**
     *信息类别: CAL_EVENT | TASK_EVENT
     */
    @ApiModelProperty(value = "信息类别",example ="CAL_EVENT" )
    private String xeventType;
    /**
     *是否为全天日程
     */
    @ApiModelProperty(value = "是否为全天日程",example ="1" )
    private boolean xisAllDayEvent;
    /**
     *是否公开
     */
    @ApiModelProperty(value = "是否公开",example ="0" )
    private boolean xisPublic;
    /**
     *地点的维度
     */
    @ApiModelProperty(value = "地点的维度",example ="")
    private String xlatitude;
    /**
     *地点说明
     */
    @ApiModelProperty(value = "地点说明",example ="实验室" )
    private String xlocationName;
    /**
     *地点的经度
     */
    @ApiModelProperty(value = "地点的经度",example ="" )
    private String xlongitude;
    /**
     *排除日期表达式RecurrenceExc (暂时不理解)
     */
    @ApiModelProperty(value = "排除日期表达式RecurrenceExc ",example ="" )
    private String xrecurrenceExc;
    /**
     *重复日期表达式RecurrenceRule FREQ=MONTHLY 每月该日，都有此日程
     */
    @ApiModelProperty(value = "重复日期表达式RecurrenceRule ",example ="FREQ=MONTHLY" )
    private String xrecurrenceRule;
    /**
     *重复日程宿主ID  当设置为重复时，记录宿主日程id
     */
    @ApiModelProperty(value = "重复日程宿主ID ",example ="45ad2c47-3ccf-45bc-b44c-58078fd28379" )
    private String xrepeatMasterId;
    /**
     *信息来源: PERSONAL| LEADER | UNIT | MEETING | BUSINESS_TRIP | HOLIDAY"
     */
    @ApiModelProperty(value = "信息来源: PERSONAL| LEADER | UNIT | MEETING | BUSINESS_TRIP | HOLIDAY ",example ="PERSONAL" )
    private String xsource;
    /**
     *日程开始时间
     */
    @ApiModelProperty(value = "日程开始时间 ",example ="2024-12-20 00:00:00" )
    private Date xstartTime;
    /**
     *日程开始时间
     */
    @ApiModelProperty(value = "日程开始时间 ",example ="2024-12-20 00:00:00" )
    private String xstartTimeStr;
    /**
     *参与者类型：PERSON | UNIT | GROUP
     */
    @ApiModelProperty(value = "参与者类型：PERSON | UNIT | GROUP ",example ="PERSON" )
    private String xtargetType;
    /**
     *日程标题
     */
    @ApiModelProperty(value = "日程标题 ",example ="学习" )
    private String xtitle;
    /**
     * 日程更新人
     */
    @ApiModelProperty(value = "日程更新人 ",example ="xadmin" )
    private String xupdatePerson;
    /**
     提醒提配置：天, 时, 分, 秒  提醒提配置：天, 时, 分, 秒 例如 0 0 -5 0  开始前五分钟提醒
     */
    @ApiModelProperty(value = "提醒提配置 天, 时, 分, 秒  提醒提配置：天, 时, 分, 秒 例如 0 0 -5 0  开始前五分钟提醒",example ="0,0,-5,0" )
    private String xvalarmTime_config;
    /**
     *提醒显示标题
     */
    @ApiModelProperty(value = "提醒显示标题 ",example ="日程提醒" )
    private String xvalarm_Summary;
    /**
     *提醒备注信息
     */
    @ApiModelProperty(value = "提醒备注信息 ",example =" " )
    private String xvalarm_description;
    /**
     *提交Email地址进行提醒，为空则不邮件提醒,
     **/
    @ApiModelProperty(value = "提交Email地址进行提醒 ",example =" " )
    private String xvalarm_mailto;
}
