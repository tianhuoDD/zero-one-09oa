package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示数据路径读取列表的实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_readdatapathlist")
public class PpEEndReaddatapathlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 结束XID，用于标识数据处理的结束点。
     */
    @TableId(value = "END_XID")
    @TableField("END_XID")
    private String endXid;

    /**
     * XREAD数据路径列表，存储了数据读取的路径信息。
     */
    private String xreadDataPathList;

    /**
     * 排序列，用于指定数据的排序顺序。
     */
    private Integer xorderColumn;

}

