/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "AttachmentDAO.h"
#include <sstream>

//// 定义一个SQL填充参数数据集添加数据宏
//#define SQLPARAMS_PUSH(__PARAMS__, __PARAM_KEY__, __VAL_TYPE__, __VAL_VAL__) \
//__PARAMS__.emplace_back(SqlParam(__PARAM_KEY__, std::make_shared<__VAL_TYPE__>(__VAL_VAL__)))

//定义条件解析宏，减少重复代码
#define ATTACHMENT_TERAM_PARSE(xapplicationID, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (xapplicationID!="A"){ \
    sql << " AND `xapplication`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, xapplicationID); \
} \

#define ATTACHMENTID_TERAM_PARSE(id, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (id!="A"){ \
    sql << " AND `xid`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, id); \
} \

uint64_t AttachmentDAO::count(const std::string& xapplicationID)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pp_e_file";
	ATTACHMENT_TERAM_PARSE(xapplicationID, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<AttachmentListDO> AttachmentDAO::GetList(const std::string& xapplicationID) {
	stringstream sql;
	sql << "SELECT xid,xname,xalias,xdescription,xapplication,xlastUpdatePerson,xlastUpdateTime,xfileName,xlength,xcreateTime,xupdateTime FROM pp_e_file";
	ATTACHMENT_TERAM_PARSE(xapplicationID, sql);//SQL填充参数宏
	AttachmentListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AttachmentListDO, AttachmentListMapper>(sqlStr, mapper, params);

}

std::list<AttachmentDetailDO> AttachmentDAO::selectByID(const std::string & xid) {
	stringstream sql;
	sql << "SELECT xid, xname, xdata, xalias, xdescription, xapplication, xlastUpdatePerson, xlastUpdateTime, xfileName, xlength, xcreateTime, xupdateTime FROM pp_e_file";
	ATTACHMENTID_TERAM_PARSE(xid, sql);//SQL填充参数宏
	AttachmentDetailMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AttachmentDetailDO, AttachmentDetailMapper>(sqlStr, mapper, params);
}

int AttachmentDAO::saveAttachment(const AttachmentDetailDO& attachment) {
	string sql = "INSERT INTO pp_e_file(xid, xname, xalias, xdescription, xapplication, xlastUpdatePerson, xlastUpdateTime, xfileName, xlength, xcreateTime, xupdateTime, xsequence, xdata, xdistributeFactor) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%dt%s%ll%dt%dt%s%s%d", attachment.getXid(), attachment.getXname(), attachment.getXalias(), attachment.getXdescription(), attachment.getXapplication(), attachment.getXlastUpdatePerson(), attachment.getXlastUpdateTime(), attachment.getXfileName(), attachment.getXlength(), attachment.getXcreateTime(), attachment.getXupdateTime(), attachment.getXsequence(), attachment.getXdata(), attachment.getXdistributeFactor());
}

int AttachmentDAO::updateAttachment(const AttachmentDetailDO& attachment) {
	string sql = "UPDATE pp_e_file SET xname=?, xalias=?, xlastUpdatePerson=?, xlastUpdateTime=?, xupdateTime=?, xdistributeFactor=? WHERE xid=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%dt%dt%d%s", attachment.getXname(), attachment.getXalias(), attachment.getXlastUpdatePerson(), attachment.getXlastUpdateTime(), attachment.getXupdateTime(), attachment.getXdistributeFactor(), attachment.getXid());
}

int AttachmentDAO::deleteAttachment(const std::string& id) {
	string sql = "DELETE FROM pp_e_file WHERE xid=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
