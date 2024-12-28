package com.zeroone.star.project.vo.j1.message.getting;

import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.apache.ibatis.type.JdbcType;

import java.time.LocalDate;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.project.vo.j1.message.getting
 * @Author: dashuai
 * @CreateTime: 2024-10-21  00:17
 * @Description: 发布消息的有关信息对应的领域模型DTO
 * @Version: 1.0
 */
@Data
@ApiModel("发布消息的有关信息数据传输对象")
public class PromulgationMessageInfoVO {
    /**
     * @description: 消息唯一标识id
     **/
    /*@ApiModelProperty(value = "编号", example = "1")
    private int xid;*/

    /**
     * @description: 消息创建时间
     **/
    /*@TableField(jdbcType = JdbcType.TIMESTAMP)
    private LocalDate xcreateTime;*/

    /**
     * @description: 消息序列号
     **/
    /*private String xsequence;*/

    /**
     * @description: 消息更新时间
     **/
    @ApiModelProperty(value = "更新时间", example = "2024-10-21")
    @TableField(jdbcType = JdbcType.TIMESTAMP)
    private LocalDate  xcreateTime;

    /**
     * @description: 消息权重
     **/
    /*@ApiModelProperty(value = "权重", example = "1")
    private int xdistributeFactor;*/

    /**
     * @description: 消息标题
     **/
    @ApiModelProperty(value = "标题", example = "嘻嘻哈哈")
    private String xtitle;

    /**
     * @description: 消息类型
     **/
    /*private String xtype;*/

    /**
     * @description: 消息内容
     **/
   /* @ApiModelProperty(value = "内容", example = "我不想写代码")
    private String xbody;*/

    /**
     * @description: 消息是否被消费
     **/
    /*private boolean xconsumed;*/

    /**
     * @description: 消息消费者
     **/
    /*@ApiModelProperty(value = "消费者", example = "张三")
    private String xconsumer;*/

    /**
     * @description: 是否为即时消息
     **/
    /*private boolean xinstant;*/

    /**
     * @description: 消息发送者
     **/
    /*@ApiModelProperty(value = "消息的接受者", example = "李四")
    private String xperson;*/

    /**
     * @description: 消息额外配置信息
     **/
    /*private String xproperties;*/
}
