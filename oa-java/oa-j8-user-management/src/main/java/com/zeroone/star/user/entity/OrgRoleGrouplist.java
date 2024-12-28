package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_role_grouplist
 */
@TableName(value = "org_role_grouplist")
@Data
public class OrgRoleGrouplist implements Serializable {

    private String roleXid;

    private String xgrouplist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}