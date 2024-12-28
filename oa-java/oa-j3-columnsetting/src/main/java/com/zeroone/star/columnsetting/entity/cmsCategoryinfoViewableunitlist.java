package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

@TableName("cms_categoryinfo_viewableunitlist")
public class cmsCategoryinfoViewableunitlist {
    @TableField("xviewableUnitList")
    private String viewableunitid;
    @TableId("CATEGORYINFO_XID")
    private String categoryid;
}
