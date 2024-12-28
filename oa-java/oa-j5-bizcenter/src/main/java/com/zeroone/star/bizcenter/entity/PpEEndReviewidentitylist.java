package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示项目结束时的评审身份列表实体类。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_end_reviewidentitylist")
public class PpEEndReviewidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 项目结束时的唯一标识符。
     */
    @TableField("END_XID")
    @TableId("END_XID")
    private String endXid;

    /**
     * 评审身份列表，记录参与项目评审的人员身份。
     */
    private String xreviewIdentityList;

    /**
     * 排序列，用于指定评审身份的顺序。
     */
    private Integer xorderColumn;

}
