package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示阅读群组列表的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_readgrouplist")
public class PpEEndReadgrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 结束XID，用于标识阅读群组的结束点。
     */
    @TableField("END_XID")
    @TableId("END_XID")
    private String endXid;

    /**
     * XREADGROUP列表，保存阅读群组的相关信息。
     */
    private String xreadGroupList;

    /**
     * 排序列，用于指定阅读群组的顺序。
     */
    private Integer xorderColumn;

}
