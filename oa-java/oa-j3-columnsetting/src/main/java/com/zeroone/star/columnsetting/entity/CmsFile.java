package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *
 * </p>
 *
 * @author lfh59 and trigger
 * @since 2024-10-26
 */
@Getter
@Setter
@Data
@TableName("cms_file")
public class CmsFile implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;

    @TableField(value = "xcreateTime",fill = FieldFill.INSERT)
    private LocalDateTime xcreateTime;

    @TableField(value = "xsequence")
    private String xsequence;

    @TableField(value = "xupdateTime",fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime xupdateTime;

    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField(value = "xalias")
    private String xalias;

    @TableField(value = "xappId")
    private String xappId;

    @TableField(value = "xdata")
    private String xdata;

    @TableField(value = "xdescription")
    private String xdescription;

    @TableField(value = "xfileName")
    private String xfileName;

    @TableField(value = "xlastUpdatePerson")
    private String xlastUpdatePerson;

    @TableField(value = "xlastUpdateTime",fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime xlastUpdateTime;

    @TableField(value = "xlength")
    private Long xlength;

    @TableField(value = "xname")
    private String xname;
}
