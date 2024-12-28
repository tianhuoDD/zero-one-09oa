package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

import lombok.Builder;
import lombok.Getter;
import lombok.Setter;

/**
 * 查询项实体类
 * 用于表示查询条件中的具体项，包含项的各类属性，如类型、值、路径等
 */
@Getter
@Setter
@TableName("qry_item")
@Builder
public class QryItem implements Serializable {

    public static final long serialVersionUID = 1L;

    /**
     * 唯一标识符
     * 用于唯一标识一个查询项
     */
    @TableId
    public String xid;

    /**
     * 创建时间
     * 记录查询项的创建时间
     */
    public LocalDateTime xcreateTime;

    /**
     * 序列号
     * 用于标识查询项的顺序或批次
     */
    public String xsequence;

    /**
     * 更新时间
     * 记录查询项的最后更新时间
     */
    public LocalDateTime xupdateTime;

    /**
     * 分配因子
     * 可能用于表示查询项在某些算法或逻辑中的权重或因子
     */
    public Integer xdistributeFactor;

    /**
     * 布尔值
     * 表示查询项的值是否为布尔类型
     */
    public Boolean xbooleanValue;

    /**
     * 组标识
     * 用于将查询项归组或分类
     */
    public String xbundle;

    /**
     * 日期时间值
     * 如果查询项的值为日期时间类型，则存储在这里
     */
    public LocalDateTime xdateTimeValue;

    /**
     * 日期值
     * 如果查询项的值为日期类型，则存储在这里
     */
    public LocalDate xdateValue;

    /**
     * 项类别
     * 描述查询项属于哪种类别
     */
    public String xitemCategory;

    /**
     * 项原始类型
     * 记录查询项的原始数据类型
     */
    public String xitemPrimitiveType;

    /**
     * 项字符串值类型
     * 如果查询项的值为字符串类型，则描述其值类型
     */
    public String xitemStringValueType;

    /**
     * 项类型
     * 记录查询项的具体类型，可能与xitemPrimitiveType有所区别
     */
    public String xitemType;

    /**
     * 数字值
     * 如果查询项的值为数字类型，则存储在这里
     */
    public Double xnumberValue;

    /**
     * 路径0
     * 查询项的路径信息，可能用于表示数据结构中的位置
     */
    public String xpath0;

    /**
     * 路径0位置
     * 与xpath0相关的位置信息，可能用于更精确地定位数据
     */
    public Integer xpath0Location;

    /**
     * 路径1到路径7及其位置
     * 类似于xpath0和xpath0Location，用于表示更多的路径信息
     */
    public String xpath1;
    public Integer xpath1Location;
    public String xpath2;
    public Integer xpath2Location;
    public String xpath3;
    public Integer xpath3Location;
    public String xpath4;
    public Integer xpath4Location;
    public String xpath5;
    public Integer xpath5Location;
    public String xpath6;
    public Integer xpath6Location;
    public String xpath7;
    public Integer xpath7Location;

    /**
     * 长字符串值
     * 如果查询项的值为字符串类型且较长，则存储在这里
     */
    public String xstringLongValue;

    /**
     * 短字符串值
     * 如果查询项的值为字符串类型且较短，则存储在这里
     */
    public String xstringShortValue;

    /**
     * 时间值
     * 如果查询项的值为时间类型，则存储在这里
     */
    public LocalTime xtimeValue;
}
