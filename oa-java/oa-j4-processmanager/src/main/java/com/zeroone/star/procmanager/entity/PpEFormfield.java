package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 
 * @TableName pp_e_formfield
 */
@TableName(value ="pp_e_formfield")
@Data
public class PpEFormfield implements Serializable {
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
    private String xapplication;

    /**
     * 
     */
    @TableField("xdataType")
    private String xdataType;

    /**
     * 
     */
    private String xform;

    /**
     * 
     */
    private String xname;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}