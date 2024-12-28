package com.zeroone.star.login.entity;

import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 菜单
 * </p>
 *
 * @author 阿伟
 */
@Getter
@Setter
public class Menu implements Serializable {

    private static final long serialVersionUID = 1L;
    /**
     * 菜单ID
     */
    private Integer menuId; //
    /**
     * 菜单名称
     */
    private String menuName;
    /**
     * 菜单类型(1为普通菜单2为目录3为内嵌iFrame4为外链跳转)
     */
    private Integer menuType;
    /**
     * 是否按钮
     */
    private Boolean isButton;
    /**
     * 父菜单ID
     */
    private String parentId;
    /**
     * 权限标识
     */
    private String permission;
    /**
     * 菜单状态（1启用 0停用）
     */
    private Integer status;

    /**
     * 所在层数，用于快速查询同层结点
     */
    private Integer level;
    /**
     * 外链跳转页面对应URL
     */
    private String linkUrl;
    /**
     * 菜单图标
     */
    private String icon;
    /**
     * 备注
     */
    private String remark;
    /**
     * 创建者ID
     */
    private String creatorId;
    /**
     * 创建时间
     */
    private Date createTime;
    /**
     * 更新者ID
     */
    private String updaterId;
    /**
     * 更新时间
     */
    private Date updateTime;
    /**
     * 逻辑删除
     */
    private Boolean deleted;

}
