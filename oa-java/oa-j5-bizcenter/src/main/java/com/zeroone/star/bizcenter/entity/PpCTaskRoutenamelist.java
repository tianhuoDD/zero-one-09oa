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
@TableName("pp_c_task_routenamelist")
public class PpCTaskRoutenamelist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String taskXid;

    private String xrouteNameList;

    private Integer xorderColumn;


}
