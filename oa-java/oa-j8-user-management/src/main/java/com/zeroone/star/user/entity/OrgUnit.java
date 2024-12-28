package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_unit
 */
@TableName(value = "org_unit")
@Data
public class OrgUnit implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private String xandfxhash;

    private String xandfxid;

    private String xdescription;

    private String xdingdinghash;

    private String xdingdingid;

    private String xdistinguishedname;

    private Integer xlevel;

    private String xlevelname;

    private String xlevelordernumber;

    private String xname;

    private Integer xordernumber;

    private String xpinyin;

    private String xpinyininitial;

    private String xqiyeweixinhash;

    private String xqiyeweixinid;

    private String xshortname;

    private String xsuperior;

    private String xunique;

    private String xwelinkhash;

    private String xwelinkid;

    private String xzhengwudingdinghash;

    private String xzhengwudingdingid;

    private static final long serialVersionUID = 1L;
}