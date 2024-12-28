package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("org_unit")
public class OrgUnit implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xandFxHash;

    private String xandFxId;

    private String xdescription;

    private String xdingdingHash;

    private String xdingdingId;

    private String xdistinguishedName;

    private Integer xlevel;

    private String xlevelName;

    private String xlevelOrderNumber;

    private String xname;

    private Integer xorderNumber;

    private String xpinyin;

    private String xpinyinInitial;

    private String xqiyeweixinHash;

    private String xqiyeweixinId;

    private String xshortName;

    private String xsuperior;

    private String xunique;

    private String xweLinkHash;

    private String xweLinkId;

    private String xzhengwuDingdingHash;

    private String xzhengwuDingdingId;


}
