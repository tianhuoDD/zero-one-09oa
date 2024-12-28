package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

@TableName("cms_categoryinfo_publishablepersonlist")
public class cmsCategoryinfoPublishablepersonlist {
    @TableId("CATEGORYINFO_XID")
    private String categoryid;
    @TableField("xpublishablePersonList")
    private String publishablepersonlist;
}
