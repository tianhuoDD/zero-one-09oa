package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示阅读单元列表的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_readunitlist")
public class PpEEndReadunitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 结束XID，用于标识阅读单元的结束点。
     */
    @TableField("END_XID")
    @TableId("END_XID")
    private String endXid;

    /**
     * 阅读单元列表，存储一系列阅读单元的信息。
     */
    private String xreadUnitList;

    /**
     * 排序列，用于指定阅读单元的顺序。
     */
    private Integer xorderColumn;

}
