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
 * @author Yuang
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("pp_e_delay")
public class PpEDelay implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xafterArriveScript;

    private String xafterArriveScriptText;

    private String xafterExecuteScript;

    private String xafterExecuteScriptText;

    private String xafterInquireScript;

    private String xafterInquireScriptText;

    private String xalias;

    private Boolean xallowReroute;

    private Boolean xallowRerouteTo;

    private String xbeforeArriveScript;

    private String xbeforeArriveScriptText;

    private String xbeforeExecuteScript;

    private String xbeforeExecuteScriptText;

    private String xbeforeInquireScript;

    private String xbeforeInquireScriptText;

    private String xdelayDataPath;

    private Integer xdelayMinute;

    private String xdelayScript;

    private String xdelayScriptText;

    private LocalDateTime xdelayTime;

    private String xdelayType;

    private String xdescription;

    private String xdisplayLogScript;

    private String xdisplayLogScriptText;

    private String xedition;

    private String xextension;

    private String xform;

    private String xgroup;

    private String xname;

    private String xopinionGroup;

    private String xposition;

    private String xprocess;

    private String xproperties;

    private String xreadDuty;

    private String xreadScript;

    private String xreadScriptText;

    private String xreviewDuty;

    private String xreviewScript;

    private String xreviewScriptText;

    private String xroute;

    private Boolean xworkMinute;


}
