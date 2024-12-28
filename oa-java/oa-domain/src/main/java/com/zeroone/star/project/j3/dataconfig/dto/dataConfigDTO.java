package com.zeroone.star.project.j3.dataconfig.dto;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@ApiModel(description = "数据配置传输数据对象")
public class dataConfigDTO implements Serializable {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "表单唯一标识符", example = "1")
    @TableId(value = "xid", type = IdType.AUTO)
    private  String xid;

    @ApiModelProperty(value = "创建时间", example = "2024-10-15T12:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "表单序列号", example = "123456")

    private String xsequence;

    @ApiModelProperty(value = "更新时间", example = "2024-10-15T12:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分发因子", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "别名", example = "form1")
    private String xalias;

    @ApiModelProperty(value = "应用ID", example = "app1")
    private String xappId;

    @ApiModelProperty(value = "Uid", example = "9015667e-69d8-434a-a1ec-4604887082ca")
    private  String xcreateorUid;

    @ApiModelProperty(value = "描述信息", example = "这是一个表单")
    private String xdescription;
    @ApiModelProperty(value = "名称", example = "name1")
    private  String xanme;
}
