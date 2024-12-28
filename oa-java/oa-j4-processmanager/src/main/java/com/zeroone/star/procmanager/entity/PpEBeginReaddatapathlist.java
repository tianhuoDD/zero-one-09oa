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
@TableName("pp_e_begin_readdatapathlist")
public class PpEBeginReaddatapathlist implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "BEGIN_XID",type = IdType.ASSIGN_ID)
    private String beginXid;

    private String xreadDataPathList;

    private Integer xorderColumn;


}
