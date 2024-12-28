package com.zeroone.star.resource.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_menu
 */
@TableName(value = "org_menu")
@Data
public class OrgMenu {

    @TableId
    private String menuId;

    private String menuName;

    private Integer menuType;

    private Integer isButton;

    private String parentId;

    private String permission;

    private Integer status;

    private Integer level;

    private String linkUrl;

    private String remark;

    private String icon;

    private String creatorId;

    private Date createTime;

    private String updaterId;

    private Date updateTime;

    private Integer deleted;
}