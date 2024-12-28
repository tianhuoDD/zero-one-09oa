package com.zeroone.star.meetingmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author caifeng
 * @since 2024-10-24
 */
@Getter
@Setter
@TableName("mt_attachment")
public class MtAttachment implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xencryptKey;

    private Boolean xdeepPath;

    private String xextension;

    private String xlastUpdatePerson;

    private LocalDateTime xlastUpdateTime;

    private Long xlength;

    private String xmeeting;

    private String xname;

    private String xstorage;

    private Boolean xsummary;


}
