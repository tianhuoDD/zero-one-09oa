package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 
 * </p>
 *
 * @author jungle
 * @since 2024-10-22
 */
@Data
@Getter
@Setter
@TableName("cms_categoryinfo")
public class CmsCategoryinfo implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    @TableField(value = "xsequence")
    private String xsequence;

    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField(value = "xcategoryAlias")
    private String xcategoryAlias;

    @TableField(value = "xcategoryName")
    private String xcategoryName;

    @TableField(value = "xdocumentType")
    private String xdocumentType;

    @TableField(value = "xcreatorPerson")
    private String xcreatorPerson;

    @TableField(value = "xappId")
    private String xappId;

    @TableField(value = "xappName")
    private String xappName;

    @TableField(value = "xparentId")
    private String xparentId;

    @TableField(value = "xsendNotify")
    private Boolean xsendNotify;

    @TableField(value = "xworkflowAppId")
    private String xworkflowAppId;

    @TableField(value = "xworkflowAppName")
    private String xworkflowAppName;

    @TableField(value = "xworkflowFlag")
    private String xworkflowFlag;

    @TableField(value = "xworkflowName")
    private String xworkflowName;

    @TableField(value = "xworkflowType")
    private String xworkflowType;

/*    private String vieablerange;

    private String publisher;

    private String manager;*/

/*    private List<String> xmanageableGroupList;
    private List<String> xmanageablePersonList;
    private List<String> xmanageableUnitList;
    private List<String> xpublishableGroupList;
    private List<String> xpublishablePersonList;
    private List<String> xpublishableUnitList;
    private List<String> xviewableGroupList;
    private List<String> xviewablePersonList;
    private List<String> xviewableUnitList;*/

}

