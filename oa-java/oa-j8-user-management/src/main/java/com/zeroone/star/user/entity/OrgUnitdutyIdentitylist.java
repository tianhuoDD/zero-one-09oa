package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_unitduty_identitylist
 */
@TableName(value = "org_unitduty_identitylist")
@Data
public class OrgUnitdutyIdentitylist implements Serializable {

    private String unitdutyXid;

    private String xidentitylist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}