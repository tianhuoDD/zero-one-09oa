package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_unitduty
 */
@TableName(value = "org_unitduty")
@Data
public class OrgUnitduty implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private String xdescription;

    private String xdistinguishedname;

    private String xname;

    private Integer xordernumber;

    private String xpinyin;

    private String xpinyininitial;

    private String xunique;

    private String xunit;

    private static final long serialVersionUID = 1L;
}