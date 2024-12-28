package com.zeroone.star.project.vo.j5.cmshome.newMessage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("新建情况下的编辑页面显示对象")
public class NewEditVO {

    /*
     * 创建人
     */
    @ApiModelProperty(value = "创建人姓名", example = "张三")
    private String xcreatorName;

    /*
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2023-04-01 00:00:00")
    private LocalDateTime xcreateTime;

    /*
     * 标题
     */
    @ApiModelProperty(value = "标题",example = "通知公告1：你们要加班")
    private String xfieldTitle;

    /*
    * 模板内容
    */
    @ApiModelProperty(value = "模板内容",example = "根据app类型不同模板内容也不同")
    private String xdata;
}
