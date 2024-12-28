package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
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
@TableName("pp_e_agent_readgrouplist")
public class PpEAgentReadgrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "AGENT_XID",type = IdType.ASSIGN_ID)
    private String agentXid;

    private String xreadGroupList;

    private Integer xorderColumn;


}
