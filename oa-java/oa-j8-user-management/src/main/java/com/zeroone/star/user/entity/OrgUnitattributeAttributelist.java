package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_unitattribute_attributelist
 */
@TableName(value = "org_unitattribute_attributelist")
@Data
public class OrgUnitattributeAttributelist implements Serializable {

    private String unitattributeXid;

    private String xattributelist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}