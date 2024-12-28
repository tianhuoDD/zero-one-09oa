package com.zeroone.star.project.dto.j4.process;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("流程分页对象")
public class PpEProcessPageDTO {

    @ApiModelProperty(value = "描述", example = "好，很好！很有精神！")
    private String xdescription;

    @ApiModelProperty(value = "图标", example = "https://tse3-mm.cn.bing.net/th/id/OIP-C.QUbrm8dICaen_1SEJkaFoQHaGv?rs=1&pid=ImgDetMain")
    private String xicon;

    @ApiModelProperty(value = "最后更新时间", example = "2024-10-22 10:25:25")
    private LocalDateTime xlastUpdateTime;

    @ApiModelProperty(value = "名称", example = "Pak Lik Sun")
    private String xname;

    @ApiModelProperty(value = "标识", example = "123456")
    private String xid;

    @ApiModelProperty(value = "顺序号", example = "sequence")
    private String xsequence;

}
