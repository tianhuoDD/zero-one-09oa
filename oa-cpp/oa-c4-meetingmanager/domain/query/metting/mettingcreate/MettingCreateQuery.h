#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _MettingCreate_QUERY_
#define _MettingCreate_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class MettingRoomQuery : public PageQuery
{
	DTO_INIT(MettingRoomQuery, PageQuery);
	// metting room
	API_DTO_FIELD_DEFAULT(String, room, ZH_WORDS_GETTER("metting.mettingcreate.query.room"));
	
};
class MettingHosterQuery : public PageQuery
{
	DTO_INIT(MettingHosterQuery, PageQuery);
	// hoster
	API_DTO_FIELD_DEFAULT(String, hoster, ZH_WORDS_GETTER("metting.mettingcreate.query.hoster"));

};
class MettingDepartQuery : public PageQuery
{
	DTO_INIT(MettingDepartQuery, PageQuery);
	// department
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("metting.mettingcreate.query.depart"));

};
class MettingMemberQuery : public PageQuery
{
	DTO_INIT(MettingMemberQuery, PageQuery);
	// member
	API_DTO_FIELD_DEFAULT(String, member, ZH_WORDS_GETTER("metting.mettingcreate.query.member"));
	API_DTO_FIELD_DEFAULT(String, identify, ZH_WORDS_GETTER("metting.mettingcreate.query.identify"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MettingCreate_QUERY_