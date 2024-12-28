package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.LocalTime;
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
@TableName("pp_c_doc_sign_scrawl")
public class PpCDocSignScrawl implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xencryptKey;

    private String xactivity;

    private String xactivityName;

    private LocalTime xcommitTime;

    private Boolean xdeepPath;

    private String xextension;

    private String xheight;

    private String xjob;

    private LocalDateTime xlastUpdateTime;

    private Long xlength;

    private String xname;

    private String xperson;

    private String xsignId;

    private String xstorage;

    private String xtype;

    private String xwidth;


}
