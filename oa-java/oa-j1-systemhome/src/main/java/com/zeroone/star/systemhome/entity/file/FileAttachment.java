package com.zeroone.star.systemhome.entity.file;

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
@TableName("file_attachment")
public class FileAttachment implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xencryptKey;

    private Boolean xdeepPath;

    private String xextension;

    private String xfolder;

    private String xlastUpdatePerson;

    private LocalDateTime xlastUpdateTime;

    private Long xlength;

    private String xname;

    private String xperson;

    private String xstorage;


}
