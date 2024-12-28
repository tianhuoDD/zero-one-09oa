package com.zeroone.star.systemhome.entity.file;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author 张大帅
 * @since 2024-10-26
 */
@Getter
@Setter
@TableName("msg_instant")
public class MsgInstant implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xbody;

    private Boolean xconsumed;

    private String xperson;

    private String xtitle;

    private String xtype;


}
