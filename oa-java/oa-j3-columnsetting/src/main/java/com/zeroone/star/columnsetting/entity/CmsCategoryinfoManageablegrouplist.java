package com.zeroone.star.columnsetting.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.List;


@Data
@Getter
@Setter
@TableName(value = "cms_categoryinfo_manageablegrouplist")
public class CmsCategoryinfoManageablegrouplist implements Serializable {
    @TableId(value = "CATEGORYINFO_XID")
    private String xcategoryid;

    @TableField(value = "xmanageableGroupList")
    private List<String> xmanageablegroupList;
}
