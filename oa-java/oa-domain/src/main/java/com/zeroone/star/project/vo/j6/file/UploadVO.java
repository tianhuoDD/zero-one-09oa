package com.zeroone.star.project.vo.j6.file;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * @program: oa-java
 * @description: 上传文件显示对象
 * @author: Mr.Wang
 * @create: 2024-10-20 17:04
 **/

@Data
@ApiModel("上传文件显示对象")
public class UploadVO {

    /**
     * 文件ID
     */
    @ApiModelProperty(value = "文件ID")
    private String id;
    /**
     * 当前时间
     */
    @ApiModelProperty(value = "当前时间")
    private DateTime date;
    /**
     * 耗时
     */
    @ApiModelProperty(value = "耗时",example = "0")
    private long spent;
    /**
     * 文件大小
     */
    @ApiModelProperty(value = "文件大小",example = "-1")
    private long size;
    /**
     * 文件数量
     */
    @ApiModelProperty(value = "文件数量",example = "1")
    private int count;
    /**
     * 文件位置
     */
    @ApiModelProperty(value = "文件位置",example = "0")
    private int position;
    /**
     * 文件访问地址
     */
    @ApiModelProperty(value = "url",example = "")
    private String url;
}
