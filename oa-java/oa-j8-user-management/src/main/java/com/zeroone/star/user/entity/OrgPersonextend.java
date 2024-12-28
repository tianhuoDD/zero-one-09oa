package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_personextend
 */
@TableName(value = "org_personextend")
@Data
public class OrgPersonextend implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private String xperson;

    private String xproperties;

    private String xtype;

    private static final long serialVersionUID = 1L;
}