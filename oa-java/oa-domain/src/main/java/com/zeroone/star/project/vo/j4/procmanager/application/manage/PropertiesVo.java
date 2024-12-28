package com.zeroone.star.project.vo.j4.procmanager.application.manage;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.extension.handlers.FastjsonTypeHandler;
import com.baomidou.mybatisplus.extension.handlers.JacksonTypeHandler;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author nefertari
 * @version 1.0.0
 */
@Data
@ApiModel("应用的部分属性显示对象")
public class PropertiesVo {
    /**
     * 默认表单
     */
    @ApiModelProperty(value = "默认表单", example = "请假")
    private String defaultForm;
    /**
     * 流程维护人
     */
    @ApiModelProperty(value = "流程维护人", example = "小王")
    private String maintenanceIdentity;
}
