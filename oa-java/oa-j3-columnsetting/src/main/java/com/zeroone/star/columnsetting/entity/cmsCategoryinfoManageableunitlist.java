package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

@TableName("cms_categoryinfo_manageableunitlist")
public class cmsCategoryinfoManageableunitlist {
    @TableField("xmanageableUnitList")
    private String manageableunitlist;
    @TableId("CATEGORYINFO_XID")
    private String categoryid;
}
