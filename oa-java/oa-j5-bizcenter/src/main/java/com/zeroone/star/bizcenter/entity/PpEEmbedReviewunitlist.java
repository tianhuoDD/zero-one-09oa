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
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_embed_reviewunitlist")
public class PpEEmbedReviewunitlist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId("EMBED_XID")
    private String embedXid;

    private String xreviewUnitList;

    private Integer xorderColumn;


}
