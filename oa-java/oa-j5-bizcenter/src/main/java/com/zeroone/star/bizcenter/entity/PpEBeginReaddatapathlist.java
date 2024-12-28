package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类用于表示特定数据路径列表的开始读取点。
 * 主要用途是记录和管理数据读取的起始位置，以便在大数据处理或者分布式系统中确保数据处理的连续性和一致性。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_readdatapathlist")
public class PpEBeginReaddatapathlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始的唯一标识符。
     * 用于标记数据读取的特定开始点，确保数据处理的连续性和一致性。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 需要读取的数据路径列表。
     * 该字段存储了一系列待处理的数据路径，以便系统能够从这些路径中读取数据。
     */
    private String xreadDataPathList;

    /**
     * 读取数据时的排序列。
     * 指定数据读取的顺序，确保数据处理的一致性和有序性。
     */
    private Integer xorderColumn;

}

