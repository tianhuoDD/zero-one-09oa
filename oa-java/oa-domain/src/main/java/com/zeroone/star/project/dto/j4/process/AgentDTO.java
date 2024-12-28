package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.ArrayList;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("脚本活动数据对象")
public class AgentDTO {
    @ApiModelProperty(value = "脚本数据的别名",example = "别名1")
    public String xalias;

    @ApiModelProperty(value = "是否允许调度，false表示不允许，true表示允许",example = "false")
    public Boolean xallowReroute;

    @ApiModelProperty(value = "是否允许调度到此活动，false表示不允许，true表示允许",example = "false")
    public Boolean xallowRerouteTo;

    @ApiModelProperty(value = "脚本数据的创建时间",example = "2024-10-24 21:21:33")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    public Date xcreateTime;

    @ApiModelProperty(value = "脚本数据的描述",example = "")
    public String xdescription;

    @ApiModelProperty(value = "脚本数据的版本",example = "CAF274795AC00001D81F16531DB017E0")
    public String xedition;

    @ApiModelProperty(value = "脚本数据的延伸",example = "")
    public String xextension;

    @ApiModelProperty(value = "脚本数据的表单",example = "")
    public String xform;

    @ApiModelProperty(value = "脚本数据的主键ID",example = "c967390c-3687-40e2-8abf-2a5caf48cee5")
    public String xid;

    @ApiModelProperty(value = "脚本数据的名字",example = "脚本")
    public String xname;

    @ApiModelProperty(value = "脚本数据的位置",example = "850,170")
    public String xposition;

    @ApiModelProperty(value = "脚本数据所属的流程",example = "17204098-a2b1-403a-9869-146991c478b2")
    public String xprocess;

    @ApiModelProperty(value = "脚本数据的性质",example = "")
    public String xproperties;

    @ApiModelProperty(value = "脚本数据的待阅人流程数据",example = "[]")
    public ArrayList<String> xreadDataPathList;

    @ApiModelProperty(value = "脚本数据的待阅人职务",example = "局长")
    public String xreadDuty;

    @ApiModelProperty(value = "脚本数据的待阅人组织",example = "[\"company1\"]")
    public ArrayList<String> xreadGroupList;

    @ApiModelProperty(value = "脚本数据的待阅人身份",example = "[\"张三\"]")
    public ArrayList<String> xreadIdentityList;

    @ApiModelProperty(value = "脚本数据的待阅人数据",example = "[]")
    public ArrayList<String> xreadUnitList;

    @ApiModelProperty(value = "脚本数据的阅读人流程数据",example = "[]")
    public ArrayList<String> xreviewDataPathList;

    @ApiModelProperty(value = "脚本数据的阅读人职务",example = "厂长")
    public String xreviewDuty;

    @ApiModelProperty(value = "脚本数据的阅读人组织",example = "[\"conmany1\"]")
    public ArrayList<String> xreviewGroupList;

    @ApiModelProperty(value = "脚本数据的阅读人身份",example = "[\"李四\"]")
    public ArrayList<String> xreviewIdentityList;

    @ApiModelProperty(value = "脚本数据的阅读人数据",example = "[]")
    public ArrayList<String> xreviewUnitList;

    @ApiModelProperty(value = "路由",example = "37bb59ef-7270-4f76-8163-6c531d3e44b8")
    public String xroute;

    @ApiModelProperty(value = "更新时间",example = "2024-10-27 18:59:52")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    public Date xupdateTime;
}
