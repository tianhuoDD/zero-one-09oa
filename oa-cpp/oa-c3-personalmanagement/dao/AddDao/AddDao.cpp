#include"AddDao.h"
// 插入数据
uint64_t AddDao::insert(const org_personDO& iObj) {
	/*string sql = "INSERT INTO `sample` (`name`, `sex` ) VALUES (?, ? )";
	return sqlSession->executeUpdate(sql, "%s%s", iObj.getRenyuanmingcheng(), iObj.getXingbie() );*/
	/*string sql = "INSERT INTO `sample` (`name`, `sex`,`id`) VALUES (?, ? ,?)";
	 
	return sqlSession->executeUpdate(sql, "%s%s%s", iObj.getXpinyin(), iObj.getXgenderType(), iObj.getXunique());*/
    //先查询一下unique编码是否重复了
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
     
      //改年龄和出生日期
      if (iObj.getXage() != -1) {
           sql = "UPDATE `org_person` SET `xage` = ?, `xbirthday` = ? WHERE `xunique` = ?;";
           ans &= sqlSession->executeUpdate(sql, "%i%s%s", iObj.getXage(), iObj.getXbirthday(), iObj.getXunique());
            
      }
     
      //改入职日期
      if (iObj.getXboardDate() != "") {
          //cout << "\n" << iObj.getXboardDate() << "\n";
          sql = "UPDATE `org_person` SET `xboardDate` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXboardDate(), iObj.getXunique());
      }
      
      //改描述
      if (iObj.getXdescription() != "") {
          sql = "UPDATE `org_person` SET `xdescription` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXdescription(), iObj.getXunique());
      }
      
      //改工号
      if (iObj.getXemployee() != "") {
         // cout << "\n" << iObj.getXemployee() << "\n";
          sql = "UPDATE `org_person` SET `xemployee` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXemployee(), iObj.getXunique());
      }
      
      //改ip地址
      if (iObj.getXipAddress() != "") {
          sql = "UPDATE `org_person` SET `xipAddress` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXipAddress(), iObj.getXunique());
      }
     
      //改邮箱
      if (iObj.getXmail() != "") {
          sql = "UPDATE `org_person` SET `xmail` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXmail(), iObj.getXunique());
      }
      
      //改办公电话
      if (iObj.getXofficePhone() != "") {
          sql = "UPDATE `org_person` SET `xofficePhone` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXofficePhone(), iObj.getXunique());
      }
      
      //改QQ号
      if (iObj.getXqq()!= "") {
          sql = "UPDATE `org_person` SET `xqq` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXqq(), iObj.getXunique());
      }
     
      //改密级标识
      if (iObj.getXsubjectSecurityClearance() != 0) {
          sql = "UPDATE `org_person` SET `xsubjectSecurityClearance` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%i%s", iObj.getXsubjectSecurityClearance(), iObj.getXunique());
      }
      
      //改汇报对象
      if (iObj.getXsuperior()!="") {
          sql = "UPDATE `org_person` AS target\
              JOIN(SELECT `xid`, `xunique` FROM `org_person` WHERE `xunique` = ? ) AS source\
              ON target.`xunique` = ?\
              SET target.xsuperior = source.`xid`;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXsuperior(), iObj.getXunique());
      }
     
      //改微信号
      if (iObj.getXweixin() != "") {
          sql = "UPDATE `org_person` SET `xweixin` = ?  WHERE `xunique` = ?;";
          ans &= sqlSession->executeUpdate(sql, "%s%s", iObj.getXweixin(), iObj.getXunique());
      }
     //如果没添加成功的话要删掉数据库里已经添加的
      if (!ans) {
          sql = "DELETE FROM `org_person` WHERE `xunique`=?;";//在人员表里删除
          sqlSession->executeUpdate(sql, "%s", iObj.getXunique());
      }



      return ans;
     

	//return sqlSession->executeInsert(sql, "%s%s", iObj.getName(), iObj.getSex(), iObj.getAge());
}