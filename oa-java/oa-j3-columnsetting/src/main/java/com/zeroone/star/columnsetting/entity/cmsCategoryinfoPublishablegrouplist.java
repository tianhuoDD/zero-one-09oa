package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

@TableName("cms_categoryinfo_publishablegrouplist")
public class cmsCategoryinfoPublishablegrouplist {
    @TableField("xpublishableGroupList")
    private String publishablegroupid;
    @TableId("CATEGORYINFO_XID")
    private String categoryid;
}
