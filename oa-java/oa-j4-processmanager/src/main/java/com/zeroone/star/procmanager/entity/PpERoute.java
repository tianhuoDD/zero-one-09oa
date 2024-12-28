package com.zeroone.star.procmanager.entity;

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
 * @author awei
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_route")
public class PpERoute implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xactivity;

    private String xactivityType;

    private String xalias;

    private String xappendTaskIdentityScript;

    private String xappendTaskIdentityScriptText;

    private String xappendTaskIdentityType;

    private String xdecisionOpinion;

    private String xdescription;

    private String xdisplayNameScript;

    private String xdisplayNameScriptText;

    private String xedition;

    private String xhiddenScript;

    private String xhiddenScriptText;

    private String xname;

    private String xopinion;

    private Boolean xopinionRequired;

    private Integer xorderNumber;

    private Boolean xpassExpired;

    private Boolean xpassSameTarget;

    private String xposition;

    private String xprocess;

    private String xproperties;

    private String xscript;

    private String xscriptText;

    private String xselectConfig;

    private Boolean xsole;

    private String xtrack;

    private String xtype;

    private String xvalidationScript;

    private String xvalidationScriptText;


}
