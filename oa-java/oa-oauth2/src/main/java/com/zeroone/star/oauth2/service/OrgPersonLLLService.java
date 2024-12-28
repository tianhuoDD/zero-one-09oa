package com.zeroone.star.oauth2.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.OrgPerson;
/**
 * @author LLL
 * @description 针对表【org_person】的数据库操作Service
 * @createDate 2024-10-21 17:42:34
 */
public interface OrgPersonLLLService extends IService<OrgPerson> {

    /**
     * 根据用户名查询用户
     * @param person
     * @return
     */
    OrgPerson getPersonByName(OrgPerson person);

}
