package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示开始评审时的数据路径列表实体。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_reviewdatapathlist")
public class PpEBeginReviewdatapathlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始XID，表示评审的唯一标识。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 评审数据路径列表，存储评审所需的数据路径。
     */
    private String xreviewDataPathList;

    /**
     * 顺序列，用于排序显示评审数据路径列表。
     */
    private Integer xorderColumn;

}
