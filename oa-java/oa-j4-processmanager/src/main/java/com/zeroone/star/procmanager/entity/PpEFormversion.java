package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 
 * @TableName pp_e_formversion
 */
@TableName(value ="pp_e_formversion")
@Data
public class PpEFormversion implements Serializable {
    /**
     * 
     */
    @TableId
    private String xid;

    /**
     * 
     */
    @TableField("xcreateTime")
    private Date xcreateTime;

    /**
     * 
     */
    private String xsequence;

    /**
     * 
     */
    @TableField("xupdateTime")
    private Date xupdateTime;

    /**
     * 
     */
    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    /**
     * 
     */
    private String xdata;

    /**
     * 
     */
    private String xform;

    /**
     * 
     */
    private String xperson;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}