package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("pp_e_split_readunitlist")
public class PpESplitReadunitlist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId("SPLIT_XID")
    private String splitXid;

    private String xreadUnitList;

    private Integer xorderColumn;


}