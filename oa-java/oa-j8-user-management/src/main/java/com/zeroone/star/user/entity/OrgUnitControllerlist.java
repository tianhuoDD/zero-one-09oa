package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_unit_controllerlist
 */
@TableName(value = "org_unit_controllerlist")
@Data
public class OrgUnitControllerlist implements Serializable {

    private String unitXid;

    private String xcontrollerlist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}