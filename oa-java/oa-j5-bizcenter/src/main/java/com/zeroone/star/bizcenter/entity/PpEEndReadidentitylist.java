package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示阅读身份列表的实体，用于记录和管理用户的阅读身份信息。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_readidentitylist")
public class PpEEndReadidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 结束XID：表示阅读身份列表的唯一标识符。
     */
    @TableField("END_XID")
    @TableId("END_XID")
    private String endXid;

    /**
     * 阅读身份列表：以字符串形式存储的阅读身份列表。
     */
    private String xreadIdentityList;

    /**
     * 排序列：用于对阅读身份列表进行排序的列。
     */
    private Integer xorderColumn;

}
