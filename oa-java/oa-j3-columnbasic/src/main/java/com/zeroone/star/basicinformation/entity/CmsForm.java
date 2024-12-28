package com.zeroone.star.basicinformation.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import com.zeroone.star.project.j3.dataconfig.vo.dataConfigDetailVO;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

/**
 * <p>
 *  表单类型
 * </p>
 *
 * @author hubery
 * @since 2024-10-20
 */
@Builder
@Getter
@Setter
@TableName("cms_form")
public class CmsForm implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField(value = "xsequence")
    private String xsequence;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField("xalias")
    private String xalias;

    @TableField("xappId")
    private String xappId;

    @TableField("xdata")
    private String xdata;

    @TableField("xdescription")
    private String xdescription;

    @TableField("xeditor")
    private String xeditor;

    @TableField("xhasMobile")
    private Boolean xhasMobile;

    @TableField("xmobileData")
    private String xmobileData;

    @TableField("xname")
    private String xname;

    @TableField("xproperties")
    private String xproperties;

}
