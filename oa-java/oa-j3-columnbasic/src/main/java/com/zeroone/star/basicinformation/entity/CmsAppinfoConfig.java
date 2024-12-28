package com.zeroone.star.basicinformation.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 *
 * @author Kokoro
 * @since 2024-10-20
 */
@Getter
@Setter
@TableName("cms_appinfo_config")
public class CmsAppinfoConfig implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    private String xsequence;

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    private String xconfig;


}
