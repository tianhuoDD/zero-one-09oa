package com.zeroone.star.project.dto.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：流程应用显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
@Data
public class ApplicationDto {
    /**
     * 名称
     */
    @ApiModelProperty(value = "名称", example = "请假管理")
    private String name;
    /**
     * 描述
     */
    @ApiModelProperty(value = "描述", example = "管理请假手续的流程")
    private String description;
    /**
     * 分类
     */
    @ApiModelProperty(value = "分类", example = "日常")
    private String category;
    /**
     * 头像地址
     */
    @ApiModelProperty(value = "头像地址", example = "+DYyw4dEiRAoAahOWl7bUkyTV4msMI4ez7UAZT44Uw4GUErqtPQGC5mjRRXg/y94RcNBJZWzBgAAAABJRU5ErkJggg==")
    private String icon;
    /**
     * 表单名称列表
     */
    @ApiModelProperty(value = "表单名称列表", example = "请假人员")
    private List<Object> formList;
    /**
     * 流程名称列表
     */
    @ApiModelProperty(value = "流程名称列表", example = "身份验证")
    private List<Object> processList;
}