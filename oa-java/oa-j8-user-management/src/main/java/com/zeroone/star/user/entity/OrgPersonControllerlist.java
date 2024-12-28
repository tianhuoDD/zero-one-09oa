package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * @TableName org_person_controllerlist
 */
@TableName(value = "org_person_controllerlist")
@Data
public class OrgPersonControllerlist implements Serializable {

    private String personXid;

    private String xcontrollerlist;

    private Integer xordercolumn;

    private static final long serialVersionUID = 1L;
}