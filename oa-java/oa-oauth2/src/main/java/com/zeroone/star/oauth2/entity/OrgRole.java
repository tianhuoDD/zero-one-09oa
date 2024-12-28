package com.zeroone.star.oauth2.entity;


import io.github.classgraph.json.Id;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.Size;
import java.sql.Timestamp;

/**
 * org_role
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class OrgRole {

    @Id
    @ApiModelProperty(value = "唯一标识", required = true)
    private String xid;

    @ApiModelProperty(value = "创建时间")
    private Timestamp xcreateTime;

    @Size(max = 128, message = "序列号长度不能超过128")
    @ApiModelProperty(value = "序列号", required = true)
    private String xsequence;


    @ApiModelProperty(value = "更新时间")
    private Timestamp xupdateTime;


    @ApiModelProperty(value = "分配因子")
    private Integer xdistributeFactor;


    @Size(max = 255, message = "描述长度不能超过255")
    @ApiModelProperty(value = "描述")
    private String xdescription;


    @Size(max = 255, message = "区分名称长度不能超过255")
    @ApiModelProperty(value = "区分名称")
    private String xdistinguishedName;


    @Size(max = 255, message = "名称长度不能超过255")
    @ApiModelProperty(value = "名称", required = true)
    private String xname;


    @ApiModelProperty(value = "排序号")
    private Integer xorderNumber;


    @Size(max = 255, message = "拼音长度不能超过255")
    @ApiModelProperty(value = "拼音")
    private String xpinyin;


    @Size(max = 255, message = "拼音首字母长度不能超过255")
    @ApiModelProperty(value = "拼音首字母")
    private String xpinyinInitial;


    @Size(max = 255, message = "唯一标识长度不能超过255")
    @ApiModelProperty(value = "唯一标识")
    private String xunique;
}
