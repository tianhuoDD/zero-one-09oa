package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

@TableName(value = "cms_categoryinfo_manageablepersonlist")
public class cmsCategoryinfoManageablepersonlist {
    @TableId(value = "CATEGORYINFO_XID")
    private String xcategoryid;
    @TableField(value = "xmanageablePersonList")
    private String xmanageablepersonlist;

}
