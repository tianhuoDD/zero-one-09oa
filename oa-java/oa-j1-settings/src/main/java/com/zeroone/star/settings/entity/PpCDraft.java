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
@TableName("pp_c_draft")
public class PpCDraft implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xapplication;

    private String xapplicationAlias;

    private String xapplicationName;

    private String xidentity;

    private String xperson;

    private String xprocess;

    private String xprocessAlias;

    private String xprocessName;

    private String xproperties;

    private String xtitle;

    private String xunit;


}
