package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *
 * </p>
 *
 * @author lenyan
 * @since 2024-10-19
 */
@Data
@TableName("cms_form")
public class CmsForm implements Serializable {

    private static final long serialVersionUID = 1L;

    // 雪花生成算法
    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField(value = "xsequence")
    private String xsequence;

    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField(value = "xalias")
    private String xalias;

    @TableField(value = "xappId")
    private String xappId;

    @TableField(value = "xdata")
    private String xdata;

    @TableField(value = "xdescription")
    private String xdescription;

    @TableField(value = "xeditor")
    private String xeditor;

    @TableField(value = "xhasMobile")
    private Boolean xhasMobile;

    @TableField(value = "xmobileData")
    private String xmobileData;

    @TableField(value = "xname")
    private String xname;

    @TableField(value = "xproperties")
    private String xproperties;
}
