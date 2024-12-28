package com.zeroone.star.procmanager;

import com.zeroone.star.procmanager.sink.AttachmentSink;
import com.zeroone.star.procmanager.source.AttachmentSource;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.stream.annotation.EnableBinding;

/**
 * <p>
 * 描述：程序启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author j4
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@EnableBinding({AttachmentSource.class, AttachmentSink.class})
public class ProcManagerApplication {

    public static void main(String[] args) {
        SpringApplication.run(ProcManagerApplication.class, args);
    }

}
