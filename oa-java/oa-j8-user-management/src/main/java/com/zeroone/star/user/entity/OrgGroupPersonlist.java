package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_group_personlist
 */
@TableName(value = "org_group_personlist")
@Data
public class OrgGroupPersonlist implements Serializable {

    private String groupXid;

    private String xpersonlist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}