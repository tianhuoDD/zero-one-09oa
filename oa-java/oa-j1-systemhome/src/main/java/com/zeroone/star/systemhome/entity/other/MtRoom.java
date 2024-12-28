package com.zeroone.star.systemhome.entity.other;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author han
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("mt_room")
public class MtRoom implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xauditor;

    private Boolean xavailable;

    private String xbuilding;

    private Integer xcapacity;

    private String xdevice;

    private Integer xfloor;

    private String xname;

    private String xphoneNumber;

    private String xphoto;

    private String xpinyin;

    private String xpinyinInitial;

    private String xroomNumber;


}
