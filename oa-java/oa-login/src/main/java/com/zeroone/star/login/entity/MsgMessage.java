package com.zeroone.star.login.entity;

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
@TableName("msg_message")
public class MsgMessage implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xbody;

    private Boolean xconsumed;

    private String xconsumer;

    private String xinstant;

    private String xperson;

    private String xproperties;

    private String xtitle;

    private String xtype;


}
