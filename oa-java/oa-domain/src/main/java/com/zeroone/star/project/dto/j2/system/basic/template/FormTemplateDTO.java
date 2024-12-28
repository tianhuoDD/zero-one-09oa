package com.zeroone.star.project.dto.j2.system.basic.template;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.time.LocalDateTime;

@Data
@ApiModel("模版管理")
@AllArgsConstructor
@NoArgsConstructor
public class FormTemplateDTO {
    @ApiModelProperty(value = "模版唯一标识符", required = true)
    @NotBlank(message = "模版的唯一标识不能为空")
    private String xid;

    @ApiModelProperty(value = "模版数据")
    private String xdata;

    @ApiModelProperty(value = "模版描述信息")
    private String xdescription;

    @ApiModelProperty(value = "模版名字")
    private String xname;

    @ApiModelProperty(value = "别名")
    private String xalias;


//    @ApiModelProperty(value = "创建时间", example = "2023-04-01T10:00:00", notes = "表示消息创建的时间")
//    @DateTimeFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
//    @NotNull(message = "创建时间不能为空")
//    private LocalDateTime xcreateTime;
//
//    @ApiModelProperty(value = "最后更新时间", example = "2023-04-01T12:00:00", notes = "表示消息最后一次更新的时间")
//    @DateTimeFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
//    private LocalDateTime xupdateTime;
//
//    @ApiModelProperty(value = "分布因子，用于负载均衡或分片", example = "3", notes = "可以帮助对模版的分布处理")
//    private Integer xdistributeFactor;

    @ApiModelProperty(value = "模版类型", example = "1", notes = "1: 表单模版，2：流程模版")
    private String xtype;

    @ApiModelProperty(value = "模版是否显示",example = "1",notes = "1: 显示，0：不显示")
    private Byte xdisplay;
}
