package com.zeroone.star.basicinformation.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author KO
 */
@Getter
@Setter
@TableName("cms_appinfo_manageablepersonlist")
public class CmsAppinfoManageablepersonlist {

    @TableField(value = "APPINFO_XID")
    private String APPINFO_XID;

    @TableField(value = "xmanageablePersonList")
    private String xmanageablePersonList;

    @TableField(value = "xorderColumn")
    private Integer xorderColumn;
}
