package com.zeroone.star.settings.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author han
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("bbs_userinfo")
public class BbsUserinfo implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xcardId;

    private Long xcreamCount;

    private Long xcredit;

    private Long xfansCount;

    private LocalDateTime xlastOperationTime;

    private LocalDateTime xlastVisitTime;

    private String xmobile;

    private String xnickName;

    private Boolean xonline;

    private Integer xorderNumber;

    private Long xoriginalCount;

    private String xpermissionContent;

    private Long xpopularity;

    private Long xreplyCount;

    private Long xreplyCountToday;

    private Integer xsex;

    private String xsignContent;

    private Long xsubjectCount;

    private Long xsubjectCountToday;

    private String xuserName;

    private String xuserStatus;


}
