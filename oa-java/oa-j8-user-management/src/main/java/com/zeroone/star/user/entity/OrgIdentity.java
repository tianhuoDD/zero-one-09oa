package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.user.base.BaseEntity;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @TableName org_identity
 */
@EqualsAndHashCode(callSuper = true)
@TableName(value = "org_identity")
@Data
public class OrgIdentity extends BaseEntity<OrgIdentity> {

    @TableId
    private String xid;

    private String xsequence;

    private Integer xdistributefactor;

    private String xdescription;

    private String xdistinguishedname;

    private Boolean xmajor;

    private String xname;

    private Integer xordernumber;

    private String xperson;

    private String xpinyin;

    private String xpinyininitial;

    private String xunique;

    private String xunit;

    private Integer xunitlevel;

    private String xunitlevelname;

    private String xunitname;

    private static final long serialVersionUID = 1L;
}