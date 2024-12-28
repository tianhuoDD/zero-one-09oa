#include"DeleteDao.h"

int DeleteDao::deleteById(string id)
{
	//角色管理表里找一下看看有没有，有就删除
	string sql = "DELETE FROM `org_role_personlist` WHERE `xpersonList`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);"; 
	 sqlSession->executeUpdate(sql, "%s", id);
	 //群组管理个人成员删掉
	sql = "DELETE FROM `org_group_personlist` WHERE `xpersonList`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);";
	sqlSession->executeUpdate(sql, "%s", id);

	sql = "DELETE FROM `org_group_identitylist` WHERE `xidentityList`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);";
	sqlSession->executeUpdate(sql, "%s", id);

	//更新汇报对象
	sql = "UPDATE `org_person` AS target SET target.`xsuperior` = ''\
		WHERE target.`xsuperior` = (\
			SELECT temp.`xid`\
			FROM(\
				SELECT `xid`\
				FROM `org_person`\
				WHERE `xunique` = ?\
			) AS temp\
			); ";
	sqlSession->executeUpdate(sql, "%s", id);

	//删除组织架构的
	sql = "DELETE FROM `org_identity` WHERE `xperson`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);";
	sqlSession->executeUpdate(sql, "%s", id);


	sql = "DELETE FROM `org_person` WHERE `xunique`=?;";//在人员表里删除

	
	return   sqlSession->executeUpdate(sql, "%s", id);
}
