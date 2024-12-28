package com.zeroone.star.bizcenter.entity;

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
 * @author xiongjian
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("pp_c_documentversion")
public class PpCDocumentversion implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xactivity;

    private String xactivityAlias;

    private String xactivityDescription;

    private String xactivityName;

    private String xactivityToken;

    private String xactivityType;

    private String xapplication;

    private String xcategory;

    private Boolean xcompleted;

    private String xdata;

    private String xjob;

    private String xperson;

    private String xprocess;


}
