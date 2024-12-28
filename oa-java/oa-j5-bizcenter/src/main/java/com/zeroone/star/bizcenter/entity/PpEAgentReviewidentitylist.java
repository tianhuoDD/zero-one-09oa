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
@TableName("pp_e_agent_reviewidentitylist")
public class PpEAgentReviewidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId(value = "AGENT_XID")
    private String agentXid;

    private String xreviewIdentityList;

    private Integer xorderColumn;


}
