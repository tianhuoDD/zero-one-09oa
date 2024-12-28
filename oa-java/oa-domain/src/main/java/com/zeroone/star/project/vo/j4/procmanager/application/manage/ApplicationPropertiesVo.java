package com.zeroone.star.project.vo.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：流程应用的属性
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
@Data
@ApiModel("流程应用的属性显示对象")
public class ApplicationPropertiesVo {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识", example = "18bf0ade-8059-4bb8-9a7a-6d621a112c59")
    private String xid;
    /**
     * 名称
     */
    @ApiModelProperty(value = "名称", example = "请假管理")
    private String xname;
    /**
     * 别名
     */
    @ApiModelProperty(value = "别名", example = "leave")
    private String xalias;
    /**
     * 描述
     */
    @ApiModelProperty(value = "描述", example = "管理请假手续的流程")
    private String xdescription;
    /**
     * 分类
     */
    @ApiModelProperty(value = "分类", example = "日常")
    private String xapplicationCategory;
    /**
     * 头像地址
     */
    @ApiModelProperty(value = "头像地址", example = "+DYyw4dEiRAoAahOWl7bUkyTV4msMI4ez7UAZT44Uw4GUErqtPQGC5mjRRXg/y94RcNBJZWzBgAAAABJRU5ErkJggg==")
    private String icon;

    /**
     * 可用成员及其所属组织
     */
    @ApiModelProperty(value = "成员及直属组织", example = "小王(1)")
    private List<IdentityVo> identityVo;
    /**
     * 可用组织vo
     */
    @ApiModelProperty(value = "可用组织", example = "研发部")
    private List<UnitVo> unitVoList;
    /**
     * 管理者
     */
    @ApiModelProperty(value = "管理者", example = "李四")
    private List<String> controller;

    /**
     * 部分属性
     */
    private PropertiesVo propertiesVo;

    /**
     * 流程维护人的组织
     */
    @ApiModelProperty(value = "流程维护人的组织", example = "财务部")
    private String maintenanceUint;
}
