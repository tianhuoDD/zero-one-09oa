package com.zeroone.star.project.vo.j2.system.basic.template;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotNull;
import java.time.LocalDateTime;

/**
 *表单模板VO
 * */
@Data
public class FormTemplateVO {
    @ApiModelProperty(value = "表单标识")
    private String xid;

    @ApiModelProperty(value = "模版数据")
    private String xdata;

    @ApiModelProperty(value = "模版描述信息")
    private String xdescription;

    @ApiModelProperty(value = "模版名字")
    private String xname;

    @ApiModelProperty(value = "模板别名")
    private String xalias;


//    @ApiModelProperty(value = "创建时间", example = "2023-04-01T10:00:00", notes = "表示消息创建的时间")
//    @NotNull(message = "创建时间不能为空")
//    private LocalDateTime xcreateTime;
//
//    @ApiModelProperty(value = "最后更新时间", example = "2023-04-01T12:00:00", notes = "表示消息最后一次更新的时间")
//    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "模版类型", example = "1", notes = "1: 表单模版，2：流程模版")
    private String xtype;
}
