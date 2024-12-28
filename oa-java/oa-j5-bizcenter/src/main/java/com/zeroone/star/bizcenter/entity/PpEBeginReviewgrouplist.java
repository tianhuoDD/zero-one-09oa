package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示评审组列表的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_reviewgrouplist")
public class PpEBeginReviewgrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始XID，用于标识评审的开始。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 评审组列表，存储评审组的相关信息。
     */
    private String xreviewGroupList;

    /**
     * 顺序列，用于维护评审组列表的顺序。
     */
    private Integer xorderColumn;

}
