package com.zeroone.star.login.entity;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
* 
* @TableName org_identity
*/
@Data
public class OrgIdentity implements Serializable {

    /**
    * 
    */
    @ApiModelProperty("")
    private String xid;
    /**
    * 
    */
    @ApiModelProperty("")
    private Date xcreatetime;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xsequence;
    /**
    * 
    */
    @ApiModelProperty("")
    private Date xupdatetime;
    /**
    * 
    */
    @ApiModelProperty("")
    private Integer xdistributefactor;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xdescription;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xdistinguishedname;
    /**
    * 
    */
    @ApiModelProperty("")
    private Boolean xmajor;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xname;
    /**
    * 
    */
    @ApiModelProperty("")
    private Integer xordernumber;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xperson;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xpinyin;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xpinyininitial;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xunique;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xunit;
    /**
    * 
    */
    @ApiModelProperty("")
    private Integer xunitlevel;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xunitlevelname;
    /**
    * 
    */
    @ApiModelProperty("")
    private String xunitname;

}
