package com.zeroone.star.login.entity;

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
@TableName("file_attachment2")
public class FileAttachment2 implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xdescription;

    private String xextension;

    private Integer xfileVersion;

    private String xfolder;

    private String xlastUpdatePerson;

    private LocalDateTime xlastUpdateTime;

    private Long xlength;

    private String xname;

    private String xoriginFile;

    private String xperson;

    private String xstatus;

    private String xtype;


}
