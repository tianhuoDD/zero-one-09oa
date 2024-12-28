package com.zeroone.star.oaj2syssecurity.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oaj2syssecurity.entity.Person;
import com.zeroone.star.oaj2syssecurity.mapper.SystemSecAdminPasswordMapper;
import com.zeroone.star.oaj2syssecurity.service.SystemSecAdminPasswordService;
import com.zeroone.star.project.vo.j2.system.security.password.AdminPasswordVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;


/**
 * <p>
 * 描述：获取和保存管理员密码，针对表【org_person】的数据库操作Mapper
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 红泥小火炉
 * @version 1.0.0
 */
@Service
public class SystemSecAdminPasswordServiceImpl extends ServiceImpl<SystemSecAdminPasswordMapper, Person>
        implements SystemSecAdminPasswordService {

    @Resource
    private SystemSecAdminPasswordMapper mapper;
    @Override
    public AdminPasswordVO getByXId(String id) {

        return mapper.getByXId(id);
    }

    @Override
    public int saveById(Person person) {
        return mapper.saveById(person);
    }
}




