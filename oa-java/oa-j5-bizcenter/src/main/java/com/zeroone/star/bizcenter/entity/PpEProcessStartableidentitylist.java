package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 可启动流程的身份列表实体类
 * 该类用于定义哪些身份有权限启动特定的流程
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_process_startableidentitylist")
public class PpEProcessStartableidentitylist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 流程的唯一标识符
     * 用于关联流程定义
     */
    @TableId("PROCESS_XID")
    private String processXid;

    /**
     * 可启动流程的身份列表
     * 存储有权启动流程的身份信息
     */
    private String xstartableIdentityList;

    /**
     * 排序列
     * 用于对身份列表进行排序
     */
    private Integer xorderColumn;

}
