package com.zeroone.star.meetingroommanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * @author: zlw
 * @date: 2024-10-28
 */

@Getter
@Setter
@TableName("mt_building")
public class MtBuilding implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private Boolean xavailable;

    private String xaddress;

    private String xname;

    private String xpinyin;

    private String xpinyinInitial;
}
