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
@TableName("pp_e_invoke_reviewidentitylist")
public class PpEInvokeReviewidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId("INVOKE_XID")
    private String invokeXid;

    private String xreviewIdentityList;

    private Integer xorderColumn;


}