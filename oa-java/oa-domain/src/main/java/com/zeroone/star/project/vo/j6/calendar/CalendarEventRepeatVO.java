package com.zeroone.star.project.vo.j6.calendar;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
@TableName("cal_event")
@ApiModel("日历日程重复对象")
public class CalendarEventRepeatVO {
    /**
     * 主键，标识宿主日程
     */
    @ApiModelProperty(value = "唯一标识",example ="123124514" )
    private String xid;
    /**
     * 日程创建时间
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
    private Boolean xalarm;
    /**
     *当前日程提醒时间
     */
    @ApiModelProperty(value = "当前日程提醒时间",example ="2024-12-19 23:55:00" )
    private Date xalarmTime;
    /**
     *当前日程对应的日历唯一标识id
     */
    private String xcalendarId;
    /**
     * 日程显示在日历上的颜色
     */
    private String xcolor;
    /**
     * 日程中备注信息，（文本框的内容 <p></p>）
     */
    private String xcomment;
    /**
     * 日程中备注信息id
     */
    private String xcommentId;
    /**
     * 日程创建人
     */
    private String xcreatePerson;
    /**
     *日程持续天数
     */
    private Integer xdaysOfDuration;
    /**
     * 日程结束时间
     */
    private Date xendTime;
    /**
     *信息类别: CAL_EVENT | TASK_EVENT
     */
    private String xeventType;
    /**
     *是否为全天日程
     */
    private Boolean xisAllDayEvent;
    /**
     *是否公开
     */
    private Boolean xisPublic;
    /**
     *地点的维度
     */
    private String xlatitude;
    /**
     *地点说明
     */
    private String xlocationName;
    /**
     *地点的经度
     */
    private String xlongitude;
    /**
     *排除日期表达式RecurrenceExc (暂时不理解)
     */
    private String xrecurrenceExc;
    /**
     *重复日期表达式RecurrenceRule FREQ=MONTHLY 每月该日，都有此日程
     */
    private String xrecurrenceRule;
    /**
     * 重复开始时间
     */
    private Date xrecurrenceStartTime;
    /**
     *重复状态：等待生成|生成完成|已删除， 删除的不再生成
     */
    private String xrepeatStatus;
    /**
     *信息来源: PERSONAL| LEADER | UNIT | MEETING | BUSINESS_TRIP | HOLIDAY"
     */
    private String xsource;
    /**
     *日程开始时间
     */
    private Date xstartTime;
    /**
     *参与者类型：PERSON | UNIT | GROUP
     */
    private String xtargetType;
    /**
     *日程标题
     */
    private String xtitle;
    /**
     * 日程更新人
     */
    private String xupdatePerson;
    /**
     提醒提配置：天, 时, 分, 秒  提醒提配置：天, 时, 分, 秒 例如 0 0 -5 0  开始前五分钟提醒
     */
    private String xvalarmTime_config;
    /**
     *提醒显示标题
     */
    private String xvalarm_Summary;
    /**
     *提醒备注信息
     */
    private String  xvalarm_description;
    /**
     *提交Email地址进行提醒，为空则不邮件提醒,
     **/
    private String xvalarm_mailto;

}
