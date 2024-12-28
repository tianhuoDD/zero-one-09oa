package com.zeroone.star.project.dto.j7.meetingroommangement;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;


@Data
@ApiModel("会议室管理数据传输对象")
public class MtRoomDTO  {
    @ApiModelProperty(value = "会议室id")
    private String xid;
    @ApiModelProperty(value = "会议室创建时间")
    private LocalDateTime xcreateTime;
    @ApiModelProperty(value = "队列")
    private String xsequence;
    @ApiModelProperty(value = "会议室更改时间")
    private LocalDateTime xupdateTime;
    @ApiModelProperty(value = "会议室分配参数")
    private Integer xdistributeFactor;
    @ApiModelProperty(value = "审核员")
    private String xauditor;
    @ApiModelProperty(value = "可用")
    private Boolean xavailable;
    @ApiModelProperty(value = "会议室位置")
    private String xbuilding;
    @ApiModelProperty(value = "会议室功能")
    private Integer xcapacity;
    @ApiModelProperty(value = "会议室仪器")
    private String xdevice;
    @ApiModelProperty(value = "会议室楼层")
    private Integer xfloor;
    @ApiModelProperty(value = "会议室名字")
    private String xname;
    @ApiModelProperty(value = "会议室电话号码")
    private String xphoneNumber;
    @ApiModelProperty(value = "会议室照片")
    private String xphoto;
    @ApiModelProperty(value = "会议室拼音")
    private String xpinyin;
    @ApiModelProperty(value = "会议室拼音缩写")
    private String xpinyinInitial;
    @ApiModelProperty(value = "会议室编号")
    private String xroomNumber;


}
