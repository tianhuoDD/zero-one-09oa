package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

import lombok.Builder;
import lombok.Data;

/**
 * @TableName org_personattribute_attributelist
 */
@TableName(value = "org_personattribute_attributelist")
@Data
@Builder
public class OrgPersonattributeAttributelist implements Serializable {

    private String personattributeXid;

    private String xattributelist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}