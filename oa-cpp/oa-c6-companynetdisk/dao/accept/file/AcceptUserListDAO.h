#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _ACCEPTUSERLIST_DAO_
#define _ACCEPTUSERLIST_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/file/file_attachment_editorlistDO.h"
#include "../../../domain/query/accept/file/AcceptUserListQuery.h"



//用户实现
class AcceptUserListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t user_count(const AcceptUserListQuery::Wrapper& query);
	// 分页查询数据
	list<file_attachment_editorlistDO> user_selectWithPage(const AcceptUserListQuery::Wrapper& query);


};
#endif // !_ACCEPTFILELIST_DAO_
