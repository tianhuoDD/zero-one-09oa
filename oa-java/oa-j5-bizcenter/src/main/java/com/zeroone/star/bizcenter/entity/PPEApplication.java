package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 应用实体类，映射到数据库中的application表。
 */
@Data
@TableName("pp_e_application")
public class PPEApplication {
    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid;//应用id

    @TableField("xcreateTime") // 创建时间
    private LocalDateTime xcreateTime;

    @TableField("xsequence") // 序列
    private String xsequence;

    @TableField("xupdateTime") // 更新时间
    private LocalDateTime xupdateTime;

    @TableField("xdistributeFactor") // 分发因子
    private Integer xdistributeFactor;

    @TableField("xalias") // 别名
    private String xalias;

    @TableField("xapplicationCategory") // 应用类别
    private String xapplicationCategory;

    @TableField("xcreatorPerson") // 创建人
    private String xcreatorPerson;

    @TableField("xdescription") // 描述
    private String xdescription;

    @TableField("xicon") // 图标
    private String xicon;

    @TableField("xiconHue") // 图标色调
    private String xiconHue;

    @TableField("xlastUpdatePerson") // 最后更新人
    private String xlastUpdatePerson;

    @TableField("xlastUpdateTime") // 最后更新时间
    private LocalDateTime xlastUpdateTime;

    @TableField("xname") // 名称
    private String xname;

    @TableField("xproperties") // 属性
    private String xproperties;
}