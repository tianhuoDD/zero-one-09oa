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
@TableName("pp_e_invoke_readidentitylist")
public class PpEInvokeReadidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;


    @TableId(value = "INVOKE_XID")
    private String invokeXid;

    private String xreadIdentityList;

    private Integer xorderColumn;


}