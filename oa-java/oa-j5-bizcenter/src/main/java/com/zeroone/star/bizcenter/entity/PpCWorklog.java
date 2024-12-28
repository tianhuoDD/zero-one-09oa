package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Builder;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("pp_c_worklog")
@Builder
public class PpCWorklog implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xapplication;

    private String xapplicationAlias;

    private String xapplicationName;

    private String xarrivedActivity;

    private String xarrivedActivityAlias;

    private String xarrivedActivityName;

    private String xarrivedActivityToken;

    private String xarrivedActivityType;

    private String xarrivedGroup;

    private String xarrivedOpinionGroup;

    private LocalDateTime xarrivedTime;

    private Boolean xcompleted;

    private Boolean xconnected;

    private Long xduration;

    private String xfromActivity;

    private String xfromActivityAlias;

    private String xfromActivityName;

    private String xfromActivityToken;

    private String xfromActivityType;

    private String xfromGroup;

    private String xfromOpinionGroup;

    private LocalDateTime xfromTime;

    private String xjob;

    private String xprocess;

    private String xprocessAlias;

    private String xprocessName;

    private String xproperties;

    private String xroute;

    private String xrouteName;

    private String xsplitToken;

    private String xsplitValue;

    private String xsplitWork;

    private Boolean xsplitting;

    private String xtype;

    private String xwork;

    private String xworkCompleted;


}
