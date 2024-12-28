package com.zeroone.star.project.dto.j1.forgotPassword;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

import java.io.Serializable;

/**
 * <p>
 * 用户实体类
 * </p>
 *
 * @author lwj
 * @since 2024-10-24
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@TableName("org_person")
public class OrgPersonDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.AUTO)
    private String xid;

    @TableField("xmobile")
    private String xmobile;

    @TableField("xname")
    private String xname;

    @TableField("xpassword")
    private String xpassword;

}
