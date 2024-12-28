package com.zeroone.star.project.vo.j2.system.basic.information;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @ClassName: SystemBasicInformationVO
 * @Package: com.zeroone.star.project.vo.j2.system.basic.information
 * @Description: 系统基本信息VO对象
 * @Author: zk
 * @Create: 2024/10/20 - 下午4:01
 */
@Data
@ApiModel(description = "系统基本信息响应VO对象")
public class SystemBasicInformationVO {
    /**
     * 是否启用连接到云平台
     */
    @ApiModelProperty(value = "是否启用连接到云平台", example = "false")
    private Boolean enable;

    /**
     * 云平台账户名称，通知显示在登录页面底部
     */
    @ApiModelProperty(value = "云平台账户名称", example = "o2oa")
    private String name;

    /**
     * 云平台密码
     */
    @ApiModelProperty(value = "云平台密码", example = "123")
    private String password;

    /**
     * 系统标题，同时显示在登录页面上部
     */
    @ApiModelProperty(value = "系统标题", example = "系统标题")
    private String title;

    /**
     * 底部申明
     */
    @ApiModelProperty(value = "底部申明", example = "底部申明")
    private String footer;

    /**
     * app下载地址
     */
    @ApiModelProperty(value = "app下载地址", example = "https://www.baidu.com")
    private String appUrl;

    /**
     * 云平台服务器地址
     */
    @ApiModelProperty(value = "云平台服务器地址", example = "https://www.jd.com")
    private String server;

    /**
     * 云平台端口
     */
    @ApiModelProperty(value = "云平台端口", example = "20080")
    private Integer port;

    /**
     * 云平台连接是否启用ssl
     */
    @ApiModelProperty(value = "云平台连接是否启用ssl", example = "false")
    private String sslEnable;

    /**
     * 推送消息secret
     */
    @ApiModelProperty(value = "推送消息secret", example = "123")
    private String secret;
    /**
     * 推送消息key
     */
    @ApiModelProperty(value = "推送消息key", example = "123")
    private String key;

    /**
     * app打包服务器域名
     */
    @ApiModelProperty(value = "app打包服务器域名", example = "apppack.o2oa.net")
    private String appPackServerHost;

    /**
     * app打包服务端口
     */

    @ApiModelProperty(value = "app打包服务端口", example = "30088")
    private Integer appPackServerPort;

    /**
     * 是否用app打包的地址服务o2oa的appUrl
     */
    @ApiModelProperty(value = "是否用app打包的地址服务o2oa的appUrl", example = "false")
    private Boolean isAppPackCoverAppUrl;

    /**
     * 扩展设置
     */
    @ApiModelProperty(value = "扩展设置", example = "123")
    private String extension;
}
