package com.zeroone.star.basicinformation.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * <p>
 * 描述：注入自定义组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chen
 * @since
 * @author Kokoro
 * @version 1.0.0
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.fastdfs",
})
public class ComponentInit {
}
