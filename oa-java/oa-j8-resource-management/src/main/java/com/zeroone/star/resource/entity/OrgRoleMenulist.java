package com.zeroone.star.resource.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * @TableName org_role_menulist
 */
@TableName(value = "org_role_menulist")
@Data
public class OrgRoleMenulist {

    private String roleId;

    private String menulist;

    private Integer xordercolumn;


}