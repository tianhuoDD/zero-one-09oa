package com.zeroone.star.basicinformation.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.models.auth.In;
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
@TableName("cms_appinfo_publishablepersonlist")
public class CmsAppinfoPublishablepersonlist {

    @TableField(value = "APPINFO_XID")
    private String APPINFO_XID;

    @TableField(value = "xpublishablePersonList")
    private String xpublishablePersonList;

    @TableField(value = "xorderColumn")
    private Integer xorderColumn;
}
