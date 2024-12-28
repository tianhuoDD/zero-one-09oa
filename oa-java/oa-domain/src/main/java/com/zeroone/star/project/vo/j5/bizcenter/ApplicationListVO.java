package com.zeroone.star.project.vo.j5.bizcenter;


import com.zeroone.star.project.dto.j5.bizcenter.ProcessDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;
import java.util.List;
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("全部应用列表对象")
public class ApplicationListVO {

    @ApiModelProperty("应用ID")
    private String id;

//    @ApiModelProperty("默认表单")
//    private String defaultForm;

    @ApiModelProperty("应用名称")
    private String name;

    @ApiModelProperty("应用分类")
    private String applicationCategory;

    @ApiModelProperty("应用图标")
    private String icon;

    @ApiModelProperty("图标色调")
    private String iconHue;

    @ApiModelProperty("最后更新时间")
    private LocalDateTime lastUpdateTime;

    @ApiModelProperty("最后更新人")
    private String lastUpdatePerson;

    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;

    @ApiModelProperty("流程列表")
    private List<ProcessDTO> processList;
}