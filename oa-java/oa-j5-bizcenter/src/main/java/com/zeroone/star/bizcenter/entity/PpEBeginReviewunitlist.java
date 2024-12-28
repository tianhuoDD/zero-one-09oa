package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示评审单位列表的相关信息，用于存储和操作评审单位的数据。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_reviewunitlist")
public class PpEBeginReviewunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始环节的唯一标识符，用于关联和识别特定的评审流程。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 审查单位列表，存储参与评审的单位信息，以便在评审过程中引用。
     */
    private String xreviewUnitList;

    /**
     * 顺序列，用于指定评审单位在列表中的显示顺序。
     */
    private Integer xorderColumn;

}

