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
 * <p>
 * 
 * </p>
 *
 * @author 阿伟
 * @since 2024-10-20
 */
@Getter
@Setter
@TableName("cms_view")
public class CmsView implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId(value = "xid", type = IdType.AUTO)
    private String xid;

    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField(value = "xsequence")
    private String xsequence;

    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField(value = "xalias")
    private String xalias;

    @TableField(value = "xappId")
    private String xappId;

    @TableField(value = "xcontent")
    private String xcontent;

    @TableField(value = "xdescription")
    private String xdescription;

    @TableField(value = "xeditor")
    private String xeditor;

    @TableField(value = "xformId")
    private String xformId;

    @TableField(value = "xname")
    private String xname;

    @TableField(value = "xorderField")
    private String xorderField;

    @TableField(value = "xorderFieldType")
    private String xorderFieldType;

    @TableField(value = "xorderType")
    private String xorderType;

    @TableField(value = "xpageSize")
    private Integer xpageSize;


}
