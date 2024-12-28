package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类用于表示开始阅读身份列表的实体。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_readidentitylist")
public class PpEBeginReadidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 开始的唯一标识符。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * 阅读身份列表，用于记录具有阅读权限的身份。
     */
    private String xreadIdentityList;

    /**
     * 排序列，用于指定列表中的顺序。
     */
    private Integer xorderColumn;

}
