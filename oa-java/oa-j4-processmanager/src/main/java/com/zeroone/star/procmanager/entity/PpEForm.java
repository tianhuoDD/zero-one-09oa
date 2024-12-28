package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *  表单do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-22
 */
@Getter
@Setter
@TableName("pp_e_form")
public class PpEForm implements Serializable {


    private static final long serialVersionUID = 1L;

    /**
     *ID唯一标识
     */
    @TableId
    private String xid;

    /**
     *创建时间
     */
    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     */
    private String xsequence;

    /**
     * 更新时间
     */

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    /**
     * 分发因子
     */

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    /**
     * 文件别名
     */
    private String xalias;

    /**
     * 所属应用程序/应用名称
     */
    private String xapplication;

    /**
     *类别
     */
    private String xcategory;

    /**
     * 数据
     */
    private String xdata;

    /**
     * 描述
     */
    private String xdescription;

    /**
     * 是否有移动端
     */
    @TableField("xhasMobile")
    private Boolean xhasMobile;

    /**
     * 图标
     */
    private String xicon;

    /**
     * 最后更新人
     */
    @TableField("xlastUpdatePerson")
    private String xlastUpdatePerson;

    /**
     * 最后更新时间
     */
    @TableField("xlastUpdateTime")
    private LocalDateTime xlastUpdateTime;

    /**
     * 移动端数据
     */
    @TableField("xmobileData")
    private String xmobileData;

    /**
     * 名称
     */
    private String xname;

    /**
     * 属性
     */
    private String xproperties;

}
