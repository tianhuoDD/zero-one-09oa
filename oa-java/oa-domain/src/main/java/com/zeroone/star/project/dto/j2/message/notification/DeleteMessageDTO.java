package com.zeroone.star.project.dto.j2.message.notification;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @Author: hjm
 * @Date: 2024/10/20/16:25
 * @Description: 删除消息操作对象
 */
@ApiModel("删除消息操作对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class DeleteMessageDTO {
    /**
     * 消息ID
     */
    @ApiModelProperty(value = "消息ID", example = "1")
    private String xid;
}