#include"DeleteDao.h"

int DeleteDao::deleteById(string id)
{
	//��ɫ���������һ�¿�����û�У��о�ɾ��
	string sql = "DELETE FROM `org_role_personlist` WHERE `xpersonList`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);"; 
	 sqlSession->executeUpdate(sql, "%s", id);
	 //Ⱥ�������˳�Աɾ��
	sql = "DELETE FROM `org_group_personlist` WHERE `xpersonList`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);";
	sqlSession->executeUpdate(sql, "%s", id);

	sql = "DELETE FROM `org_group_identitylist` WHERE `xidentityList`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);";
	sqlSession->executeUpdate(sql, "%s", id);

	//���»㱨����
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

	//ɾ����֯�ܹ���
	sql = "DELETE FROM `org_identity` WHERE `xperson`=(SELECT `xid` FROM `org_person` WHERE `xunique`=?);";
	sqlSession->executeUpdate(sql, "%s", id);


	sql = "DELETE FROM `org_person` WHERE `xunique`=?;";//����Ա����ɾ��

	
	return   sqlSession->executeUpdate(sql, "%s", id);
}
