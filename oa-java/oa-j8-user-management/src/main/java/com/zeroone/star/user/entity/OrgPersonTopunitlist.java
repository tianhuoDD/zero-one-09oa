package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_person_topunitlist
 */
@TableName(value = "org_person_topunitlist")
@Data
public class OrgPersonTopunitlist implements Serializable {

    private String personXid;

    private String xtopunitlist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}