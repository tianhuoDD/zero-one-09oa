package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_person
 */
@TableName(value = "org_person")
@Data
public class OrgPerson implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private Integer xage;

    private String xandfxhash;

    private String xandfxid;

    private Date xbirthday;

    private Date xboarddate;

    private Date xchangepasswordtime;

    private String xdescription;

    private String xdingdinghash;

    private String xdingdingid;

    private String xdistinguishedname;

    private String xemployee;

    private Integer xfailurecount;

    private Date xfailuretime;

    private String xgendertype;

    private Boolean xhiddenmobile;

    private String xicon;

    private String xiconldpi;

    private String xiconmdpi;

    private String xipaddress;

    private String xlanguage;

    private String xlastloginaddress;

    private String xlastloginclient;

    private Date xlastlogintime;

    private Date xlocktime;

    private String xmail;

    private String xmobile;

    private String xmpwxopenid;

    private String xname;

    private String xnickname;

    private String xofficephone;

    private String xopen1id;

    private String xopen2id;

    private String xopen3id;

    private String xopen4id;

    private String xopen5id;

    private Integer xordernumber;

    private String xpassword;

    private Date xpasswordexpiredtime;

    private String xpinyin;

    private String xpinyininitial;

    private String xqiyeweixinhash;

    private String xqiyeweixinid;

    private String xqq;

    private String xsignature;

    private String xstatus;

    private String xstatusdes;

    private Integer xsubjectsecurityclearance;

    private String xsuperior;

    private String xunique;

    private String xwelinkhash;

    private String xwelinkid;

    private String xweixin;

    private String xzhengwudingdinghash;

    private String xzhengwudingdingid;

    private static final long serialVersionUID = 1L;
}