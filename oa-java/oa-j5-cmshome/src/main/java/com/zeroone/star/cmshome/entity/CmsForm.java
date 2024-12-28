package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
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
 * @author yuanzijie
 * @since 2024-10-24
 * @author huangfeifan
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("cms_form")
public class CmsForm implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xalias;

    private String xappId;

    private String xdata;

    private String xdescription;

    private String xeditor;

    private Boolean xhasMobile;

    private String xmobileData;

    private String xname;

    private String xproperties;


}
