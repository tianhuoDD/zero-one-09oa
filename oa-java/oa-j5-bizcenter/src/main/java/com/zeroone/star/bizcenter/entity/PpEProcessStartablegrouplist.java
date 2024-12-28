package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示可启动流程的组列表实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_process_startablegrouplist")
public class PpEProcessStartablegrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 流程的唯一标识符。
     */
    @TableId("PROCESS_XID")
    private String processXid;

    /**
     * 可启动流程的组列表，用于定义哪些组有权限启动流程。
     */
    private String xstartableGroupList;

    /**
     * 排序列，用于指定列表中的顺序。
     */
    private Integer xorderColumn;

}
