package com.zeroone.star.systemhome.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author 李云毅
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("org_group_unitlist")
public class OrgGroupUnitlist implements Serializable {

    private static final long serialVersionUID = 1L;

    private String groupXid;

    private String xunitList;

    private Integer xorderColumn;


}
