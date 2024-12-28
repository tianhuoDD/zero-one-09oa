package com.zeroone.star.oauth2.service.impl.oauth2;


import com.zeroone.cloud.oauth2.entity.SecurityUser;
import com.zeroone.cloud.starter.oauth2.service.LoadUserDetailService;

import com.zeroone.star.oauth2.service.OrgPersonLLLService;
import com.zeroone.star.oauth2.entity.OrgPerson;
import com.zeroone.star.oauth2.entity.OrgRole;
import com.zeroone.star.oauth2.service.OrgRoleLLLService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.List;
import java.util.stream.Collectors;


/**
 * <p>
 * 描述：加载用户信息服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
@Slf4j
public class LoadUserDetailServiceImpl implements LoadUserDetailService {
    @Resource
    OrgPersonLLLService OrgPersonService;
    @Resource
    OrgRoleLLLService orgRoleLLLService;

    @Override
    @Transactional
    public SecurityUser loadUserDetailForMgr(String username) throws UsernameNotFoundException {

       System.out.println(username);
        //对username进行解码
        try {
            username= URLDecoder.decode(username, "UTF-8");
            // 1 通过用户名查找用户对象
            log.info("用户名：{}", username);
            OrgPerson person = new OrgPerson();
            person.setXname(username);
            person = OrgPersonService.getPersonByName(person);
            if (person == null) {
                throw new UsernameNotFoundException("用户名或密码错误");
            }

            // 2 通过用户ID获取角色列表
            List<OrgRole> roles = orgRoleLLLService.listRoleByUserId(person.getXid());
            // 3 构建权限角色对象

            return SecurityUser.create(person, person.getXname(), person.getXpassword(), roles.stream().map(OrgRole::getXunique).collect(Collectors.toList()));

        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public SecurityUser loadUserDetailForUser(String username) throws UsernameNotFoundException {
        throw new UsernameNotFoundException("用户端查找用户尚未实现");

    }

}
