package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示项目结束时的评审单位列表实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_reviewunitlist")
public class PpEEndReviewunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 项目结束时的唯一标识符。
     */
    @TableField("END_XID")
    @TableId("END_XID")
    private String endXid;

    /**
     * 评审单位列表的字符串表示，通常是一个JSON数组。
     */
    private String xreviewUnitList;

    /**
     * 用于排序的列值，确保评审单位按照特定顺序展示。
     */
    private Integer xorderColumn;

}
