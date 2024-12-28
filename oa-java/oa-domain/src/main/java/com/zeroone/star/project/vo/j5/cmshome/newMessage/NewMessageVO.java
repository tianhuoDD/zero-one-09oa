package com.zeroone.star.project.vo.j5.cmshome.newMessage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("新建消息显示对象")
public class NewMessageVO {

     /*
      * 所属种类图标
     */
     @ApiModelProperty(value = "所属app的图标", example = "dashboard")
     private String xcategoryIcon;

     /*
      * 所属种类名称
     */
     @ApiModelProperty(value = "所属app名称", example = "通知公告")
     private String xcategoryName;

     /*
      * 新建单位
     */
     @ApiModelProperty(value = "新建单位",example = "开发部")
     private String xcreatorUnitName;

     /*
      * 创建人
     */
     @ApiModelProperty(value = "创建人姓名", example = "张三")
     private String xcreatorName;

     /*
      * 创建时间
     */
     @ApiModelProperty(value = "创建时间", example = "2023-04-01 00:00:00")
     private String xcreateTime;

     /*
      * 标题
     */
     @ApiModelProperty(value = "标题",example = "通知公告1：你们要加班")
     private String title;
}
