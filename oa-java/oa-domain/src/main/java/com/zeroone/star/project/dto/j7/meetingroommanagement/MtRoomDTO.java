package com.zeroone.star.project.dto.j7.meetingroommanagement;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@Getter
@Setter
@TableName("mt_room")
@ApiModel(value = "MtRoomDTO对象", description = "会议室")
public class MtRoomDTO implements Serializable {

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
