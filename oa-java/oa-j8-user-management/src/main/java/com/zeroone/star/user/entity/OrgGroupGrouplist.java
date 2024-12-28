package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_group_grouplist
 */
@TableName(value = "org_group_grouplist")
@Data
public class OrgGroupGrouplist implements Serializable {

    private String groupXid;

    private String xgrouplist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}