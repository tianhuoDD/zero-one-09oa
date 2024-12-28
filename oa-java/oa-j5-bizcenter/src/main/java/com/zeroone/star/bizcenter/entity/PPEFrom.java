package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 实体类，映射到数据库中的pp_e_form表
 */
@Data
@TableName("pp_e_form")
public class PPEFrom {

    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid; // 主键ID；

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime; // 创建时间；

    @TableField("xsequence")
    private String xsequence; // 序列；

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime; // 更新时间；

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor; // 分发因子；

    @TableField("xalias")
    private String xalias; // 别名；

    @TableField("xapplication")
    private String xapplication; // 应用标识；

    @TableField("xcategory")
    private String xcategory; // 分类；

    @TableField("xdata")
    private String xdata; // 表单数据；

    @TableField("xdescription")
    private String xdescription; // 描述；

    @TableField("xhasMobile")
    private Boolean xhasMobile; // 是否有移动端版本；

    @TableField("xicon")
    private String xicon; // 表单图标；

    @TableField("xlastUpdatePerson")
    private String xlastUpdatePerson; // 最后更新人；

    @TableField("xlastUpdateTime")
    private LocalDateTime xlastUpdateTime; // 最后更新时间；

    @TableField("xmobileData")
    private String xmobileData; // 移动端特定数据；

    @TableField("xname")
    private String xname; // 表单名称；

    @TableField("xproperties")
    private String xproperties; // 表单属性；
}