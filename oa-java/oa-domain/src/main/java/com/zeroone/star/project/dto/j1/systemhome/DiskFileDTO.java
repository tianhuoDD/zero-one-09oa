package com.zeroone.star.project.dto.j1.systemhome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import java.math.BigInteger;
import java.util.Date;

/**
 * 查询网盘文件信息
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("网盘文件查询信息")
public class DiskFileDTO {
    /**
     * 唯一编号
     */
    @ApiModelProperty(value = "唯一编号", example = "132123123132", required = true)
    private String xid;
    /**
     * 文件名
     */
    @ApiModelProperty(value = "文件名", example = "飞翔的小狗", required = false)
    private String xname;
    /**
     * 扩展名
     */
    @ApiModelProperty(value = "扩展名", example = "jpg/png", required = false)
    private String xextension;
    /**
     * 序列号
     */
    @ApiModelProperty(value = "序列号", example = "aaaaaaaaaaaaaaaaa", required = false)
    private String xsequence;
    /**
     * 文件所有者的姓名
     */
    @ApiModelProperty(value = "文件所有者的姓名", example = "机哥", required = false)
    private String xperson;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2024-10-21", required = true)
    private Date xcreateTime;
    /**
     * 最新修改时间
     */
    @ApiModelProperty(value = "最新修改时间", example = "2024-10-21", required = false)
    private Date xlastUpdateTime;
    /**
     * 最新更新该文件的用户
     */
    @ApiModelProperty(value = "最新更新该文件的用户", example = "东东哥", required = false)
    private String xlastUpdatePerson;
    /**
     * 文件大小
     */
    @ApiModelProperty(value = "文件大小", example = "1234G", required = false)
    private BigInteger xlength;
    /**
     * 存储位置
     */
    @ApiModelProperty(value = "文件存储位置", example = "http://www.baidu.com/test.jpg", required = false)
    private String xstorage;
    /**
     * 文件描述
     */
    @ApiModelProperty(value ="文件描述", example = "这是一张图片", required = false)
    private String xdescription;



}
