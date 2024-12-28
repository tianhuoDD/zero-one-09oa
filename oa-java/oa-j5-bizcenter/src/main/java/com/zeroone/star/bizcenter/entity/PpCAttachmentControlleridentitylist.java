package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("pp_c_attachment_controlleridentitylist")
public class PpCAttachmentControlleridentitylist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId("ATTACHMENT_XID")
    private String attachmentXid;

    private String xcontrollerIdentityList;

    private Integer xorderColumn;


}
