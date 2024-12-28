package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示开始阅读单元列表的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_readunitlist")
public class PpEBeginReadunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始的唯一标识符。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 阅读单元列表的字符串表示。
     */
    private String xreadUnitList;

    /**
     * 排序列的值，用于列表中的排序。
     */
    private Integer xorderColumn;

}
