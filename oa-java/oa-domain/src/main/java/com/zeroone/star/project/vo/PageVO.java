package com.zeroone.star.project.vo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * @author Qhbee
 * @version 1.0 2024/10/21 下午9:04
 * 分页查询结果分装类
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class PageVO {
    private Long total; // 总记录数
    private List rows;  // 数据列表
}