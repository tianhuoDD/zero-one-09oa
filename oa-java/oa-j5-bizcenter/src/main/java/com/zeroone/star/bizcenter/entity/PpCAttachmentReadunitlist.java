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
@TableName("pp_c_attachment_readunitlist")
public class PpCAttachmentReadunitlist implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId("ATTACHMENT_XID")
    private String attachmentXid;

    private String xreadUnitList;

    private Integer xorderColumn;


}
