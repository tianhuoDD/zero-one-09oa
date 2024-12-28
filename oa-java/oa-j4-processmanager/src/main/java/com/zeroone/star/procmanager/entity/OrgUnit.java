package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *  组织do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-22
 */
@Getter
@Setter
@TableName("org_unit")
public class OrgUnit implements Serializable {
    /**
     *串行版本ID
     */
    private static final long serialVersionUID = 1L;
    /**
     *ID唯一标识
     */
    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;
    /**
     *创建时间
     */
    private LocalDateTime xcreateTime;
    /**
     *序列号
     */
    private String xsequence;
    /**
     *更新时间
     */
    private LocalDateTime xupdateTime;
    /**
     *分配因子。可能用于负载均衡或数据分片
     */
    private Integer xdistributeFactor;
    /**
     *AND Fx哈希值。可能是某种加密或校验用的哈希值。
     */
    private String xandFxHash;
    /**
     *AND Fx ID。可能是某种关联ID。
     */
    private String xandFxId;
    /**
     *描述
     */
    private String xdescription;
    /**
     *DingDing哈希值。可能是钉钉应用相关的哈希值
     */
    private String xdingdingHash;
    /**
     * DingDing ID。可能是钉钉应用相关的ID。
     */
    private String xdingdingId;
    /**
     *区别名。
     */
    private String xdistinguishedName;
    /**
     *级别。
     */
    private Integer xlevel;
    /**
     *级别名称
     */
    private String xlevelName;
    /**
     *级别顺序号
     */
    private String xlevelOrderNumber;
    /**
     *名称
     */
    private String xname;
    /**
     *顺序号
     */
    private Integer xorderNumber;
    /**
     *拼音。可能用于存储组织单元名称的拼音表示。
     */
    private String xpinyin;
    /**
     *拼音首字母
     */
    private String xpinyinInitial;
    /**
     *企业微信哈希值
     */
    private String xqiyeweixinHash;
    /**
     *企业微信ID
     */
    private String xqiyeweixinId;
    /**
     *简称
     */
    private String xshortName;
    /**
     *上级
     */
    private String xsuperior;
    /**
     *唯一标识符
     */
    private String xunique;
    /**
     *WeLink哈希值
     */
    private String xweLinkHash;
    /**
     *WeLink ID
     */
    private String xweLinkId;
    /**
     *政务钉钉哈希值
     */
    private String xzhengwuDingdingHash;
    /**
     *政务钉钉ID
     */
    private String xzhengwuDingdingId;

    @Override
    public String toString() {
        return "OrgUnit{" +
                "xid='" + xid + '\'' +
                ", xcreateTime=" + xcreateTime +
                ", xsequence='" + xsequence + '\'' +
                ", xupdateTime=" + xupdateTime +
                ", xdistributeFactor=" + xdistributeFactor +
                ", xandFxHash='" + xandFxHash + '\'' +
                ", xandFxId='" + xandFxId + '\'' +
                ", xdescription='" + xdescription + '\'' +
                ", xdingdingHash='" + xdingdingHash + '\'' +
                ", xdingdingId='" + xdingdingId + '\'' +
                ", xdistinguishedName='" + xdistinguishedName + '\'' +
                ", xlevel=" + xlevel +
                ", xlevelName='" + xlevelName + '\'' +
                ", xlevelOrderNumber='" + xlevelOrderNumber + '\'' +
                ", xname='" + xname + '\'' +
                ", xorderNumber=" + xorderNumber +
                ", xpinyin='" + xpinyin + '\'' +
                ", xpinyinInitial='" + xpinyinInitial + '\'' +
                ", xqiyeweixinHash='" + xqiyeweixinHash + '\'' +
                ", xqiyeweixinId='" + xqiyeweixinId + '\'' +
                ", xshortName='" + xshortName + '\'' +
                ", xsuperior='" + xsuperior + '\'' +
                ", xunique='" + xunique + '\'' +
                ", xweLinkHash='" + xweLinkHash + '\'' +
                ", xweLinkId='" + xweLinkId + '\'' +
                ", xzhengwuDingdingHash='" + xzhengwuDingdingHash + '\'' +
                ", xzhengwuDingdingId='" + xzhengwuDingdingId + '\'' +
                '}';
    }
}
