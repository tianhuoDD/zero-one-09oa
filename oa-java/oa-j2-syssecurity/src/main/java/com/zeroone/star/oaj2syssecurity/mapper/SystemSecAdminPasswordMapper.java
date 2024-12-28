package com.zeroone.star.oaj2syssecurity.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oaj2syssecurity.entity.Person;
import com.zeroone.star.project.vo.j2.system.security.password.AdminPasswordVO;
import org.apache.ibatis.annotations.Mapper;


/**
 * <p>
 * 描述：获取和保存管理员密码，针对表【org_person】的数据库操作Mapper
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 红泥小火炉
 * @version 1.0.0
 */
@Mapper
public interface SystemSecAdminPasswordMapper extends BaseMapper<Person> {

    AdminPasswordVO getByXId(String id);

    int saveById(Person person);
}




