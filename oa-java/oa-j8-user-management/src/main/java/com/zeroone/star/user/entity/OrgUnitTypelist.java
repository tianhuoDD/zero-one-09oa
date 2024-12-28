package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_unit_typelist
 */
@TableName(value = "org_unit_typelist")
@Data
public class OrgUnitTypelist implements Serializable {

    private String unitXid;

    private String xtypelist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}