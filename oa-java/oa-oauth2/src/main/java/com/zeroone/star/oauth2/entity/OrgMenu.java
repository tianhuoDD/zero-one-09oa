package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.TableLogic;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 菜单权限表
 * </p>
 *
 * @author 阿伟
 */
@Getter
@Setter
@Data
@TableName("org_menu")
public class OrgMenu implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 菜单ID
     */
    @TableId(value = "menu_id", type = IdType.ASSIGN_ID)
    private String menuId;

    /**
     * 菜单名称
     */
    @TableField("menu_name")
    private String menuName;

    /**
     * 菜单类型(1为普通菜单2为目录3为内嵌iFrame4为外链跳转)
     */
    @TableField("menu_type")
    private Integer menuType;

    /**
     * 是否按钮
     */
    @TableField("is_button")
    private Boolean isButton;

    /**
     * 父菜单ID
     */
    @TableField("parent_id")
    private String parentId;

    /**
     * 权限标识
     */
    @TableField("permission")
    private String permission;

    /**
     * 菜单状态（1启用 0停用）
     */
    @TableField("status")
    private Integer status;

    /**
     * 菜单图标
     */
    @TableField("icon")
    private String icon;

    /**
     * 所在层数，用于快速查询同层结点
     */
    @TableField("level")
    private Integer level;

    /**
     * 外链跳转页面对应URL
     */
    @TableField("link_url")
    private String linkUrl;

    /**
     * 备注
     */
    @TableField("remark")
    private String remark;

    /**
     * 创建者ID
     */
    @TableField("creator_id")
    private String creatorId;

    /**
     * 创建时间
     */
    @TableField("create_time")
    private Date createTime;

    /**
     * 更新者ID
     */
    @TableField("updater_id")
    private String updaterId;

    /**
     * 更新时间
     */
    @TableField("update_time")
    private Date updateTime;

    /**
     * 逻辑删除
     */
    @TableLogic
    @TableField("deleted")
    private Boolean deleted;
}
