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
@TableName("pp_e_publish_reviewunitlist")
public class PpEPublishReviewunitlist implements Serializable {

    private static final long serialVersionUID = 1L;


    @TableId(value = "PUBLISH_XID")
    private String publishXid;

    private String xreviewUnitList;

    private Integer xorderColumn;


}
