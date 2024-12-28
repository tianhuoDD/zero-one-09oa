package com.zeroone.star.project.j3.dataconfig.vo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
@ApiModel(description = "数据配置显示对象")
public class dataConfigVO implements Serializable {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "表单唯一标识符", example = "6cde7836-cf96-4dd5-9769-0b2cbc174bc7")
    private  String id;

    @ApiModelProperty(value = "应用ID", example = "96f3f3f8-249e-4192-9943-c9f5a2f2cdc8")
    private String appId;

    @ApiModelProperty(value = "名称", example = "df1")
    private  String name;

    @ApiModelProperty(value = "别名", example = "kunge")
    private String alias;

    @ApiModelProperty(value = "描述信息", example = "这是一个表单")
    private String description;

    @ApiModelProperty(value = "创建时间", example = "2024-10-15 12:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "更新时间", example = "2024-10-15 12:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime updateTime;
}
