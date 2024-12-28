package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_role
 */
@TableName(value = "org_role")
@Data
public class OrgRole implements Serializable {

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

    private static final long serialVersionUID = 1L;
}