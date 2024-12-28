package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 草稿实体/pp_c_draft
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_c_draft")
public class PpCDraft implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableField("xid")
    private String xid;

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField("xsequence")
    private String xsequence;

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField("xapplication")
    private String xapplication;

    @TableField("xapplicationAlias")
    private String xapplicationAlias;

    @TableField("xapplicationName")
    private String xapplicationName;

    @TableField("xidentity")
    private String xidentity;

    @TableField("xperson")
    private String xperson;

    @TableField("xprocess")
    private String xprocess;

    @TableField("xprocessAlias")
    private String xprocessAlias;

    @TableField("xprocessName")
    private String xprocessName;

    @TableField("xproperties")
    private String xproperties;

    @TableField("xtitle")
    private String xtitle;

    @TableField("xunit")
    private String xunit;


}
