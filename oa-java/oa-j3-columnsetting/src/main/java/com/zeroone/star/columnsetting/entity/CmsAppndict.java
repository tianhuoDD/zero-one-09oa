package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
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
 * @author ikun
 * @author luo
 * @since 2024-10-20
 */
@Getter
@Setter
@TableName("cms_appndict")
public class CmsAppndict implements Serializable {

    private static final long serialVersionUID = 1L;
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
    @TableField(value = "xcreatorUid")
    private String xcreatorUid;
    @TableField(value = "xdescription")
    private String xdescription;
    @TableField(value = "xname")
    private String xname;

}
