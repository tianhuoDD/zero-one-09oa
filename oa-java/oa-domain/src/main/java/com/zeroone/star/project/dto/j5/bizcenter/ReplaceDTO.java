package com.zeroone.star.project.dto.j5.bizcenter;



import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("重置处理人模型")
public class ReplaceDTO {
    @ApiModelProperty(value = "处理人标识集合" ,required = true)
    private List<String> distinguishedNameList;

    @ApiModelProperty(value = "重置身份",required = true)
    private List<String> identityList;

    @ApiModelProperty(value = "重置意见",example = "重置给: 财务部员工1, 财务部员工2",required = true)
    private String opinion;

    @ApiModelProperty(value = "路由名称",example ="重置给: 财务部员工1, 财务部员工2",required = true)
    private String routeName;
}
