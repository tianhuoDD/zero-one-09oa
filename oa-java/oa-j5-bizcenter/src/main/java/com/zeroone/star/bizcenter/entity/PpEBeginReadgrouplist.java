package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类用于表示阅读群组列表的起始点信息，是数据表pp_e_begin_readgrouplist的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_begin_readgrouplist")
public class PpEBeginReadgrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * beginXid是阅读起始点的唯一标识符。
     */
    @TableField("BEGIN_XID")
    private String beginXid;

    /**
     * xreadGroupList存储了阅读群组的列表信息。
     */
    private String xreadGroupList;

    /**
     * xorderColumn用于指定阅读群组列表的排序列。
     */
    private Integer xorderColumn;

}

