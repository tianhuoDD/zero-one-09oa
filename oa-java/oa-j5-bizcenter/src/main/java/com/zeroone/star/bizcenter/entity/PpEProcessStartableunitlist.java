package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 可启动流程单元列表实体类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_process_startableunitlist")
public class PpEProcessStartableunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 流程的唯一标识符
     */
    @TableId("PROCESS_XID")
    private String processXid;

    /**
     * 可启动单元列表的XID，用于标识特定的启动单元配置
     */
    private String xstartableUnitList;

    /**
     * 排序列，用于定义列表中的顺序
     */
    private Integer xorderColumn;

}
