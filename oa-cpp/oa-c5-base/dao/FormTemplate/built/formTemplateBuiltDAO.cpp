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
#include "formTemplateBuiltDAO.h"
#include "formTemplateBuiltMapper.h"
#include <sstream>




uint64_t formTemplateBuiltDAO::insert(const formTemplateBuiltDO& iObj)
{
	 string sql = "INSERT INTO `sys_templateform` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xalias`, `xcategory`, `xdata`, `xdescription`, `xicon`, `xmobileData`, `xname`, `xoutline`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%ull%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateTime(), iObj.getSequence(), iObj.getUpdateTime(), iObj.getDistributeFactor(), iObj.getAlias(), iObj.getCategory(), iObj.getData(), iObj.getDescription(), iObj.getIcon(), iObj.getMobileData(), iObj.getName(), iObj.getOutline());
}


int formTemplateBuiltDAO::deleteById(uint64_t xid)
{
	string sql = "DELETE FROM `sys_templateform` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%ull", xid);
}