package com.zeroone.star.project.dto.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotEmpty;
import java.util.List;


/**
 * <p>
 * 描述：流程应用的属性显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
@Data
public class ApplicationPropertiesDto {
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
     * 默认表单
     */
    @ApiModelProperty(value = "默认表单", example = "请假")
    private String xproperties;
    /**
     * 头像地址
     */
    @ApiModelProperty(value = "头像地址", example = "+DYyw4dEiRAoAahOWl7bUkyTV4msMI4ez7UAZT44Uw4GUErqtPQGC5mjRRXg/y94RcNBJZWzBgAAAABJRU5ErkJggg==")
    private String xicon;
    /**
     * 可用身份
     */
    @ApiModelProperty(value = "可用身份", example = "张三")
    private List<String> availableIdentity;
    /**
     * 可用身份的组织
     */
    @ApiModelProperty(value = "可用身份的组织", example = "研发部")
    private String availableIdentityUnit;
    /**
     * 可用组织
     */
    @ApiModelProperty(value = "可用组织", example = "研发部")
    private List<String> availableUnit;
    /**
     * 管理者
     */
    @ApiModelProperty(value = "管理者", example = "李四")
    private List<String> controller;
    /**
     * 流程维护人
     */
    @ApiModelProperty(value = "流程维护人", example = "小王")
    private String maintenance;

    /**
     * 流程维护人的组织
     */
    @ApiModelProperty(value = "流程维护人的组织", example = "财务部")
    private String maintenanceUint;
}
