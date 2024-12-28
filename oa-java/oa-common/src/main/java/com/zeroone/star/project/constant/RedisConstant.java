package com.zeroone.star.project.constant;

/**
 * <p>
 * 描述：Redis相关常量
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface RedisConstant {
    /**
     * 角色资源映射Map的key
     */
    String RESOURCE_ROLES_MAP = "AUTH:RESOURCE_ROLES";
    /**
     * 定时消息的key
     */
    String SCHEDULED_MESSAGES_KEY = "scheduled_messages";
    /**
     * 未发送的消息的key
     */
    String UNSEND_MESSAGES_KEY = "unsend_messages";
}
