package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_a_empower
 */
@TableName(value = "org_a_empower")
@Data
public class OrgAEmpower implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private String xapplication;

    private String xapplicationalias;

    private String xapplicationname;

    private Date xcompletedtime;

    private String xedition;

    private Boolean xenable;

    private String xfilterlistdata;

    private String xfromidentity;

    private String xfromperson;

    private Boolean xkeepenable;

    private String xprocess;

    private String xprocessalias;

    private String xprocessname;

    private Date xstarttime;

    private String xtoidentity;

    private String xtoperson;

    private String xtype;

    private static final long serialVersionUID = 1L;
}