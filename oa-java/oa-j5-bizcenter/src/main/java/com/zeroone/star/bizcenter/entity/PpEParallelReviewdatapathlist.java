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
@TableName("pp_e_parallel_reviewdatapathlist")
public class PpEParallelReviewdatapathlist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId("PARALLEL_XID")
    private String parallelXid;

    private String xreviewDataPathList;

    private Integer xorderColumn;


}
