package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * 进程控制器列表实体类
 * 该类用于定义和进程控制器相关的属性，包括进程的唯一标识、控制器列表以及排序列
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_process_controllerlist")
public class PpEProcessControllerlist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 进程的唯一标识符
     * 用于唯一确定一个进程
     */
    @TableId("PROCESS_XID")
    private String processXid;

    /**
     * 控制器列表
     * 包含与当前进程相关的控制器信息
     */
    private String xcontrollerList;

    /**
     * 排序列
     * 用于指定控制器列表的排序顺序
     */
    private Integer xorderColumn;

}
