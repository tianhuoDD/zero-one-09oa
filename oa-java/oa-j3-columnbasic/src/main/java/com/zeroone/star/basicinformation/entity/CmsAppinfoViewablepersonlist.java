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
@TableName("cms_appinfo_viewablepersonlist")
public class CmsAppinfoViewablepersonlist {

    @TableField(value = "APPINFO_XID")
    private String APPINFO_XID;

    @TableField(value = "xviewablePersonList")
    private String xviewablePersonList;

    @TableField(value = "xorderColumn")
    private Integer xorderColumn;
}
