package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_a_empowerlog
 */
@TableName(value = "org_a_empowerlog")
@Data
public class OrgAEmpowerlog implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private String xactivity;

    private String xactivityalias;

    private String xactivityname;

    private String xapplication;

    private String xapplicationalias;

    private String xapplicationname;

    private Date xempowertime;

    private String xfromidentity;

    private String xfromperson;

    private String xjob;

    private String xprocess;

    private String xprocessalias;

    private String xprocessname;

    private String xtitle;

    private String xtoidentity;

    private String xtoperson;

    private String xwork;

    private static final long serialVersionUID = 1L;
}