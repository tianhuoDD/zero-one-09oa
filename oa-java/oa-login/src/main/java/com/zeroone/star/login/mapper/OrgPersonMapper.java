package com.zeroone.star.login.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.OrgPerson;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;


/**
* @author 29720
* @description 针对表【org_person】的数据库操作Mapper
* @createDate 2024-10-21 17:42:34
* @Entity generator.domain.com.j1.login.doamin.OrgPerson
*/
@Mapper
public interface OrgPersonMapper extends BaseMapper<OrgPerson> {
	/**
	 * 根据姓名查询人员信息
	 * @param xname
	 * @return
	 */
	OrgPerson getPersonByName(String xname);

	void updateByXMobile(OrgPerson person);

	@Select("select * from org_person where xid = #{xid}")
	OrgPerson getUserInfoById(String id);
}
