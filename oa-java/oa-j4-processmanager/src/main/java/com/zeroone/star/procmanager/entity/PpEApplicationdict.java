package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *  数据配置do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("pp_e_applicationdict")
public class PpEApplicationdict implements Serializable {

    private static final long serialVersionUID = 1L;
    /**
     *唯一标识
     */
    private String xid;
    /**
     *创建时间
     */
    private LocalDateTime xcreateTime;
    /**
     *序列号
     */
    private String xsequence;
    /**
     *上次更新时间
     */
    private LocalDateTime xupdateTime;
    /**
     *分布因素
     */
    private Integer xdistributeFactor;
    /**
     *别名
     */
    private String xalias;
    /**
     *应用
     */
    private String xapplication;
    /**
     *描述
     */
    private String xdescription;
    /**
     *名称
     */
    private String xname;

}
