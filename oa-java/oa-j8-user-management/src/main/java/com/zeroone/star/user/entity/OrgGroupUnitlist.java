package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_group_unitlist
 */
@TableName(value = "org_group_unitlist")
@Data
public class OrgGroupUnitlist implements Serializable {

    private String groupXid;

    private String xunitlist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}