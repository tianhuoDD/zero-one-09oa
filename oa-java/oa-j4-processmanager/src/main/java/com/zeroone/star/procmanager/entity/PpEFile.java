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
 *  附件do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("pp_e_file")
public class PpEFile implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    @TableId
    private String xid;

    /**
     * 创建时间
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
     * 所属应用程序
     */
    private String xapplication;

    /**
     * dfs存储路径
     */
    private String xurl;

    /**
     * 描述
     */
    private String xdescription;

    /**
     * 文件名称
     */
    @TableField("xfileName")
    private String xfileName;

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
     * 文件大小
     */
    private Long xlength;

    /**
     * 名称
     */
    private String xname;

}
