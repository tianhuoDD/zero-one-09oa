package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 本类表示手动路由列表的实体类，用于在系统中持久化手动路由的相关信息。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-26
 */
@Getter
@Setter
@TableName("pp_e_manual_routelist")
public class PpEManualRoutelist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 手动XID：唯一标识每个手动路由条目的ID。
     */
    @TableField("MANUAL_XID")
    private String manualXid;

    /**
     * 路由列表：存储路由信息的字段，可能包含多个路由的详细信息。
     */
    private String xrouteList;

    /**
     * 排序列：用于指定路由列表中的显示顺序。
     */
    private Integer xorderColumn;

}

