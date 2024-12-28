package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 进程版本实体类，用于表示业务中心中的进程实例版本信息。
 * 该类实现了Serializable接口，确保进程版本信息可以被序列化和反序列化，便于网络传输和存储。
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Getter
@Setter
@TableName("pp_e_processversion")
public class PpEProcessversion implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 进程版本唯一标识符，用于唯一标识一个进程版本。
     */
    @TableId
    private String xid;

    /**
     * 进程版本创建时间，用于记录进程版本的创建时间。
     */
    private LocalDateTime xcreateTime;

    /**
     * 进程版本序列号，用于表示进程版本的顺序。
     */
    private String xsequence;

    /**
     * 进程版本更新时间，用于记录进程版本信息的最后更新时间。
     */
    private LocalDateTime xupdateTime;

    /**
     * 进程版本分配因子，用于表示进程版本的分配权重或优先级。
     */
    private Integer xdistributeFactor;

    /**
     * 进程版本数据，用于存储进程版本的具体内容或配置信息。
     */
    private String xdata;

    /**
     * 进程版本负责人，用于表示负责该进程版本的人员。
     */
    private String xperson;

    /**
     * 进程版本进程标识符，用于关联该进程版本所属的进程。
     */
    private String xprocess;

}
