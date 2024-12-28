package com.zeroone.star.procmanager.entity;

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
 * @author Yuang
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("pp_e_parallel_readunitlist")
public class PpEParallelReadunitlist implements Serializable {

    private static final long serialVersionUID = 1L;


    @TableId(value = "PARALLEL_XID")
    private String parallelXid;

    private String xreadUnitList;

    private Integer xorderColumn;


}
