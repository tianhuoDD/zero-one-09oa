package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示评审身份列表的相关信息，用于存储和操作评审身份数据。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_reviewidentitylist")
public class PpEBeginReviewidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始XID，用于标识评审过程的唯一性。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 评审身份列表，存储具体的评审身份信息。
     */
    private String xreviewIdentityList;

    /**
     * 顺序列，用于维持评审身份列表的顺序。
     */
    private Integer xorderColumn;

}
