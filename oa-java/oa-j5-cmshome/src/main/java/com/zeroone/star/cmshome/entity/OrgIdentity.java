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
 * @since 2024-10-25
 */
@Getter
@Setter
@TableName("org_identity")
public class OrgIdentity implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xdescription;

    private String xdistinguishedName;

    private Boolean xmajor;

    private String xname;

    private Integer xorderNumber;

    private String xperson;

    private String xpinyin;

    private String xpinyinInitial;

    private String xunique;

    private String xunit;

    private Integer xunitLevel;

    private String xunitLevelName;

    private String xunitName;


}
