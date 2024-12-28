package com.zeroone.star.project.query.j7.meetingroommanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author Qhbee
 * @version 1.0 2024/10/21 下午10:36
 */
@Getter
@Setter
@ToString
@ApiModel("会议室查询(分页+条件)")
public class MtRoomQuery extends PageQuery {
    @ApiModelProperty("会议室位置")
    private String xBuilding;
}
