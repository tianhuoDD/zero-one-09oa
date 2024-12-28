package com.zeroone.star.project.dto.j5.bizcenter;

import lombok.Data;

import java.time.LocalDateTime;

/**
 * @program: oa-java
 * @description: 工作详情实体
 * @author: hamhuo
 * @create: 2024-10-29 22:47
 **/
@Data
public class PpCWorkDTO {
   /* private String xid; // 替换 id 为 xid
    private String xjob; // 添加前缀 x*/
    private String xtitle; // 添加前缀 x
   /* private String xserial; // 添加前缀 x
    private LocalDateTime xstartTime; // 添加前缀 x
    private String xstartTimeMonth; // 添加前缀 x
    private String xapplication; // 添加前缀 x
    private String xapplicationName; // 添加前缀 x
    private String xapplicationAlias; // 添加前缀 x
    private String xprocess; // 添加前缀 x
    private String xprocessName; // 添加前缀 x
    private String xprocessAlias; // 添加前缀 x*/
    private String xcreatorPerson; // 添加前缀 x
    /*private String xcreatorIdentity; // 添加前缀 x
    private String xcreatorUnit; // 添加前缀 x
    private String xproperties; // 添加前缀 x，类型根据实际需要调整*/
}
