package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.*;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *  应用do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-22
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
@TableName("pp_e_application")
public class PpEApplication implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;

    /**
     * 创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     */
    private String xsequence;

    /**
     * 更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分布因素
     */
    private Integer xdistributeFactor;

    /**
     * 别名
     */
    private String xalias;

    /**
     * 类型
     */
    private String xapplicationCategory;

    /**
     * 创建用户
     */
    private String xcreatorPerson;

    /**
     * 描述
     */
    private String xdescription;

    /**
     * 头像url
     */
    private String xicon;

    /**
     * 头像图片颜色
     */
    private String xiconHue;

    /**
     * 最后更新应用的用户
     */
    private String xlastUpdatePerson;

    /**
     * 最后更新时间
     */
    private LocalDateTime xlastUpdateTime;

    /**
     * 名称
     */
    private String xname;

    /**
     * 应用属性 （默认表单，流程维护人）
     */
    private String xproperties;


}
