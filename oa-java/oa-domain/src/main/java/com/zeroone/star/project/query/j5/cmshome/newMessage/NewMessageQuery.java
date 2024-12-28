package com.zeroone.star.project.query.j5.cmshome.newMessage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@ApiModel("新建消息输入标题时所需的查询对象")
public class NewMessageQuery {

    @ApiModelProperty(value = "appId", example = "cms_appinfo表中的xid")
    private String xappId; //需要通过查询appId来查询正在新建的app的图标和名称

    @ApiModelProperty(value = "身份ID", example = "org_identity表中的xid")
    private String xidentityId; //查询的是org_identity表中的id，包含姓名和部门
}
