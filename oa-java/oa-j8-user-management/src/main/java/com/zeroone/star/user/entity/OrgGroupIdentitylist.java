package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_group_identitylist
 */
@TableName(value = "org_group_identitylist")
@Data
public class OrgGroupIdentitylist implements Serializable {

    private String groupXid;

    private String xidentitylist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}