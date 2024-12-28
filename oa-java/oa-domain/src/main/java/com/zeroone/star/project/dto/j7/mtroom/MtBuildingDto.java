package com.zeroone.star.project.dto.j7.mtroom;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;

/**
 * @author: zlw
 * @date: 2024-10-30
 */

@Data
@ApiModel("会议室管理传输数据对象")
public class MtBuildingDto {

    @ApiModelProperty(value = "会议id",example = "1")
    private String xid;

    @ApiModelProperty(value = "会议创建时间",example = "2024-10-21 19:47:42")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "队列",example = "1111")
    private String xsequence;

    @ApiModelProperty(value = "会议修改时间",example = "2024-10-21 19:47:42")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分配参数",example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "是否开启",example = "false")
    private Boolean xavailable;

    @ApiModelProperty(value = "地址",example = "花园大街")
    private String xaddress;

    @ApiModelProperty(value = "名字",example = "地王大厦")
    private String xname;

    @ApiModelProperty(value = "拼音",example = "diwangdasha")
    private String xpinyin;

    @ApiModelProperty(value = "拼音配置项",example = "不知")
    private String xpinyinInitial;
}
