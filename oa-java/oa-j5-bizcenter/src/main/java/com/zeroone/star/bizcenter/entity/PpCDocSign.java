package com.zeroone.star.bizcenter.entity;

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
 * @author xiongjian
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("pp_c_doc_sign")
public class PpCDocSign implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xactivity;

    private String xactivityName;

    private String xapplication;

    private LocalDateTime xcommitTime;

    private String xjob;

    private String xperson;

    private String xprocess;

    private String xproperties;

    private String xsignScrawlId;

    private Integer xstatus;

    private String xtaskId;

    private String xtitle;


}
