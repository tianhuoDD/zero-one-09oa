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
@TableName("pp_e_manual")
public class PpEManual implements Serializable {

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

    private Boolean xallowAddSplit;

    private Boolean xallowDeleteWork;

    private Boolean xallowPause;

    private Boolean xallowPress;

    private Boolean xallowRapid;

    private Boolean xallowReroute;

    private Boolean xallowRerouteTo;

    private Boolean xallowReset;

    private Boolean xallowRetract;

    private Boolean xallowRollback;

    private String xbeforeArriveScript;

    private String xbeforeArriveScriptText;

    private String xbeforeExecuteScript;

    private String xbeforeExecuteScriptText;

    private String xbeforeInquireScript;

    private String xbeforeInquireScriptText;

    private String xdescription;

    private String xdisplayLogScript;

    private String xdisplayLogScriptText;

    private String xedition;

    private String xextension;

    private String xform;

    private String xgroup;

    private String xmanualAfterTaskScript;

    private String xmanualAfterTaskScriptText;

    private String xmanualBeforeTaskScript;

    private String xmanualBeforeTaskScriptText;

    private Boolean xmanualMergeSameJobActivity;

    private String xmanualMode;

    private String xmanualStayScript;

    private String xmanualStayScriptText;

    private Boolean xmanualUncompletedTaskToRead;

    private String xname;

    private String xopinionGroup;

    private String xposition;

    private String xprocess;

    private String xproperties;

    private String xreadDuty;

    private String xreadScript;

    private String xreadScriptText;

    private Integer xresetCount;

    private String xresetRange;

    private String xresetRangeScriptText;

    private String xreviewDuty;

    private String xreviewScript;

    private String xreviewScriptText;

    private String xtaskDuty;

    private Integer xtaskExpireDay;

    private Integer xtaskExpireHour;

    private String xtaskExpireScript;

    private String xtaskExpireScriptText;

    private String xtaskExpireType;

    private Boolean xtaskExpireWorkTime;

    private String xtaskScript;

    private String xtaskScriptText;


}
