#include"AddDao.h"
// ��������
uint64_t AddDao::insert(const org_personDO& iObj) {
	/*string sql = "INSERT INTO `sample` (`name`, `sex` ) VALUES (?, ? )";
	return sqlSession->executeUpdate(sql, "%s%s", iObj.getRenyuanmingcheng(), iObj.getXingbie() );*/
	/*string sql = "INSERT INTO `sample` (`name`, `sex`,`id`) VALUES (?, ? ,?)";
	 
	return sqlSession->executeUpdate(sql, "%s%s%s", iObj.getXpinyin(), iObj.getXgenderType(), iObj.getXunique());*/
    //�Ȳ�ѯһ��unique�����Ƿ��ظ���
    string sql = " SELECT `xunique` FROM `org_person` where xunique =?";
    auto res = sqlSession->executeQueryNumerical(sql,"%s",iObj.getXunique());
    if (res) {
        return 0;
    }

    
      sql = "INSERT INTO `org_person` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`,`xdistinguishedName`,\
        `xmobile` ,`xname`  ,`xorderNumber` ,`xpassword` ,`xstatus`,`xunique` ,`xgenderType` , `xpinyin`,\
        `xpinyinInitial`     \
        ) VALUES(? , ? , ? , ? , ? ,?,?,?,?,?,?,?,?,?);";
    
      auto ans= sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%s%s", iObj.getXid(),
          iObj.getXcreateTime(),
          iObj.getXsequence(),
          iObj.getXupdateTime(),
          iObj.getXdistinguishedName(),
          iObj.getXmobile(),
          iObj.getXname(),
          iObj.getXorderNumber(),
          iObj.getXpassword(),
          iObj.getXstatus(),
          iObj.getXunique(),
          iObj.getXgenderType(),
          iObj.getXpinyin(),
          iObj.getXpinyinInitial()
        );
     
      //������ͳ�������
      if (iObj.getXage() != -1) {
           sql = "UPDATE `org_person` SET `xage` = ?, `xbirthday` = ? WHERE `xunique` = ?;";
           ans &= sqlSession->executeUpdate(sql, "%i%s%s", iObj.getXage(), iObj.getXbirthday(), iObj.getXunique());
            
      }
     
      //����ְ����
      if (iObj.getXboardDate() != "") {
          //cout << "\n" << iObj.getXboardDate() << "\n";
          sql = "UPDATE `org_person` SET `xboardDate` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXboardDate(), iObj.getXunique());
      }
      
      //������
      if (iObj.getXdescription() != "") {
          sql = "UPDATE `org_person` SET `xdescription` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXdescription(), iObj.getXunique());
      }
      
      //�Ĺ���
      if (iObj.getXemployee() != "") {
         // cout << "\n" << iObj.getXemployee() << "\n";
          sql = "UPDATE `org_person` SET `xemployee` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXemployee(), iObj.getXunique());
      }
      
      //��ip��ַ
      if (iObj.getXipAddress() != "") {
          sql = "UPDATE `org_person` SET `xipAddress` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXipAddress(), iObj.getXunique());
      }
     
      //������
      if (iObj.getXmail() != "") {
          sql = "UPDATE `org_person` SET `xmail` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXmail(), iObj.getXunique());
      }
      
      //�İ칫�绰
      if (iObj.getXofficePhone() != "") {
          sql = "UPDATE `org_person` SET `xofficePhone` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXofficePhone(), iObj.getXunique());
      }
      
      //��QQ��
      if (iObj.getXqq()!= "") {
          sql = "UPDATE `org_person` SET `xqq` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXqq(), iObj.getXunique());
      }
     
      //���ܼ���ʶ
      if (iObj.getXsubjectSecurityClearance() != 0) {
          sql = "UPDATE `org_person` SET `xsubjectSecurityClearance` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%i%s", iObj.getXsubjectSecurityClearance(), iObj.getXunique());
      }
      
      //�Ļ㱨����
      if (iObj.getXsuperior()!="") {
          sql = "UPDATE `org_person` AS target\
              JOIN(SELECT `xid`, `xunique` FROM `org_person` WHERE `xunique` = ? ) AS source\
              ON target.`xunique` = ?\
              SET target.xsuperior = source.`xid`;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXsuperior(), iObj.getXunique());
      }
     
      //��΢�ź�
      if (iObj.getXweixin() != "") {
          sql = "UPDATE `org_person` SET `xweixin` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXweixin(), iObj.getXunique());
      }
     //���û��ӳɹ��Ļ�Ҫɾ�����ݿ����Ѿ���ӵ�
      if (!ans) {
          sql = "DELETE FROM `org_person` WHERE `xunique`=?;";//����Ա����ɾ��
          sqlSession->executeUpdate(sql, "%s", iObj.getXunique());
      }



      return ans;
     

	//return sqlSession->executeInsert(sql, "%s%s", iObj.getName(), iObj.getSex(), iObj.getAge());
}