package com.zeroone.star.bizcenter.entity;

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
 * @since 2024-10-30
 */
@Getter
@Setter
@TableName("pp_c_task_routelist")
public class PpCTaskRoutelist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String taskXid;

    private String xrouteList;

    private Integer xorderColumn;


}
