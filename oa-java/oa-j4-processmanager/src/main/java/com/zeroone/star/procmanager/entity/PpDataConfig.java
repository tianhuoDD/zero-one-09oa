package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("pp_data_config")
public class PpDataConfig {
    @TableId(type = IdType.ASSIGN_UUID)
    private String id;
    private String name;
    private String alias;
    private String description;
    private String category;
    private String icon;
    private String formList;
    private String processList;
}