package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * @TableName org_oauthcode
 */
@TableName(value = "org_oauthcode")
@Data
public class OrgOauthcode implements Serializable {

    @TableId
    private String xid;

    private Date xcreatetime;

    private String xsequence;

    private Date xupdatetime;

    private Integer xdistributefactor;

    private String xaccesstoken;

    private String xclientid;

    private String xcode;

    private Boolean xcodeused;

    private String xperson;

    private String xscope;

    private static final long serialVersionUID = 1L;
}