package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

@TableName("cms_categoryinfo_viewablepersonlist")
public class cmsCategoryinfoViewablepersonlist {
    @TableId("CATEGORYINFO_XID")
    private String categoryid;
    @TableField("xviewablePersonList")
    private String viewablepersonlist;
}
