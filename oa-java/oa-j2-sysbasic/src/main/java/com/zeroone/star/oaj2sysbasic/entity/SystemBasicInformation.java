package com.zeroone.star.oaj2sysbasic.entity;

import lombok.Data;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

/**
 * @ClassName: SystemBasicInformation
 * @Package: com.zeroone.star.oaj2sysbasic.entity
 * @Description: 系统基本信息
 * @Author: zk
 * @Create: 2024/10/24 - 下午12:10
 */
@Data
@Document
public class SystemBasicInformation {
    /**
    * 系统基本信息id
    */
    @Id
    private String id;

    /**
    * 是否启用连接到云平台
    */
    private boolean enable;
    /**
    * 云平台账户名称
    */
    private String name;
    /**
    * 云平台密码
    */
    private String password;
    /**
    * 系统标题
    */
    private String title;
    /**
    * 底部申明，系统副标题
    */
    private String footer;
    /**
    * app下载地址
    */
    private String appUrl;
    /**
    * 云平台服务器地址
    */
    private String server;
    /**
    * 云平台端口
    */
    private Integer port;
    /**
     * 云平台连接是否启用ssl
    */
    private Boolean sslEnable;
    /**
    * 推送消息secret
    */
    private String secret;
    /**
    * 推送消息key
    */
    private String key;
    /**
    * app打包服务器域名
    */
    private String appPackServerHost;
    /**
    * app打包服务器端口
    */
    private Integer appPackServerPort;
    /**
    * 是否启用app打包的地址覆盖o2oa的appUrl
    */
    private boolean isAppPackCoverAppUrl;
    /**
     * 扩展设置
    */
    private String extension;
}
