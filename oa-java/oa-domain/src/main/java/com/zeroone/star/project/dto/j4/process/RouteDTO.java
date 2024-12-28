package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;
import java.util.ArrayList;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("路由数据信息")
public class RouteDTO {

    @ApiModelProperty(value = "主键ID",example = "cc88613a-637d-41fb-ace6-8f4ba4a0063b")
    private String xid;

    @ApiModelProperty(value = "创建时间",example = "2024-10-24 21:21:33")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "更新时间",example = "2024-10-27 19:38:42")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "路由指向的那个活动",example = "00ebd98f-727c-4c65-9083-0d8af6825828")
    private String xactivity;

    @ApiModelProperty(value = "路由指向的那个活动他的类型",example = "manual")
    private String xactivityType;

    @ApiModelProperty(value = "别名",example = "别名1")
    private String xalias;

    @ApiModelProperty(value = "描述信息",example = "")
    private String xdescription;

    @ApiModelProperty(value = "版本信息",example = "CAF272ECC55000017BFBE6801DBB7650")
    private String xedition;

    @ApiModelProperty(value = "名字",example = "取消")
    private String xname;

    @ApiModelProperty(value = "位置信息",example = "680,160")
    private String xposition;

    @ApiModelProperty(value = "流程信息",example = "17204098-a2b1-403a-9869-146991c478b2")
    private String xprocess;

    @ApiModelProperty(value = "属性", example = "[]")
    private ArrayList<String> xproperties;

    @ApiModelProperty(value = "轨迹",example = "")
    private String xtrack;

}
