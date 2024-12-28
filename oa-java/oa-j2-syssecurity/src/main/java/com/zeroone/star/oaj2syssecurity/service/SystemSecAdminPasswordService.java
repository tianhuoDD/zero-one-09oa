package com.zeroone.star.oaj2syssecurity.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oaj2syssecurity.entity.Person;
import com.zeroone.star.project.vo.j2.system.security.password.AdminPasswordVO;


/**
 * <p>
 * 描述：获取和保存管理员密码，针对表【org_person】的数据库操作Mapper
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 红泥小火炉
 * @version 1.0.0
 */
public interface SystemSecAdminPasswordService extends IService<Person> {

    AdminPasswordVO getByXId(String id);

    int saveById(Person person);
}
