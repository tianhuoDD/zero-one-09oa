package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_role_personlist
 */
@TableName(value = "org_role_personlist")
@Data
public class OrgRolePersonlist implements Serializable {

    private String roleXid;

    private String xpersonlist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}