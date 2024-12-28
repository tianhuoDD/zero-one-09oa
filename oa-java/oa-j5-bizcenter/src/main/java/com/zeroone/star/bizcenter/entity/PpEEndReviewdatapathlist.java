package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示最终审查数据路径列表的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_reviewdatapathlist")
public class PpEEndReviewdatapathlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 审查的最终XID，用于标识特定的审查流程。
     */
    @TableField("END_XID")
    @TableId("END_XID")
    private String endXid;

    /**
     * 审查数据路径列表，存储审查所需的数据路径。
     */
    private String xreviewDataPathList;

    /**
     * 顺序列，用于指定数据路径的审查顺序。
     */
    private Integer xorderColumn;

}
