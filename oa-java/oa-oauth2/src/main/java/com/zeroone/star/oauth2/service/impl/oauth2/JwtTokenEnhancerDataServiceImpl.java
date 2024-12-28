package com.zeroone.star.oauth2.service.impl.oauth2;

import com.zeroone.cloud.oauth2.entity.SecurityUser;
import com.zeroone.cloud.starter.oauth2.service.JwtTokenEnhancerDataService;

import com.zeroone.star.oauth2.entity.OrgPerson;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Map;


/**
 * <p>
 * 描述：Jwt Token增强数据处理服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class JwtTokenEnhancerDataServiceImpl implements JwtTokenEnhancerDataService {
    @Override
    public Map<String, Object> enhance(SecurityUser securityUser) {
        // 获取数据库用户DO对象
        OrgPerson person = (OrgPerson) securityUser.getExtendsObject();
        Map<String, Object> info = new HashMap<>(1);
        // 把用户ID设置到JWT中
        info.put("id", person.getXid());
        // 添加用户名到JWT中
        info.put("name", person.getXname());
        // 添加用户序列号到JWT中
        info.put("xsequence", person.getXsequence());
        // 添加区分名称到JWT中
        info.put("xdistinguishedName", person.getXdistinguishedName());
        return info;
    }
}
