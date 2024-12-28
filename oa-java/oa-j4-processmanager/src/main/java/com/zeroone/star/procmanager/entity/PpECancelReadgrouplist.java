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
@TableName("pp_e_cancel_readgrouplist")
public class PpECancelReadgrouplist implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "CANCEL_XID")
    private String cancelXid;

    private String xreadGroupList;

    private Integer xorderColumn;


}
