package com.zeroone.star.project.dto.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("新建消息时的上传对象")
public class NewMessageDTO {

    /*
     * 所属app的id
     */
    @ApiModelProperty(value = "所属app的id", example = "cms_appinfo表中的xid")
    private String xappId;

    /*
     * 所属分类id
     */
    @ApiModelProperty(value = "所属分类id", example = "cms_categoryinfo表中的xid")
    private String xcategoryId;

    /*
     * 标题
     */
    @ApiModelProperty(value = "标题",example = "通知公告1：你们要加班")
    private String xtitle;

    @ApiModelProperty(value = "身份ID", example = "org_identity表中的xid")
    private String xidentityId; //查询的是org_identity表中的id，包含姓名和部门

    /*
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2023-04-01 00:00:00")
    private LocalDateTime xcreateTime;

}
