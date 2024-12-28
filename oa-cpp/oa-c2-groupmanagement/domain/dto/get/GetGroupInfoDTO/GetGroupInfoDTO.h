#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 18:40:29

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
#ifndef _GetGroupInfoDTO_H_
#define _GetGroupInfoDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GetGroupInfoDTO : public oatpp::DTO
{
	DTO_INIT(GetGroupInfoDTO,DTO);
	//名字
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("groupManagement.groupInfo.field.name"));
	//群组唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"));
	//描述
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("groupManagement.groupInfo.field.description"));
	
	////群组唯一标识
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"));
	////创建时间
	//API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("groupManagement.groupInfo.field.createTime"));
	////序列
	//API_DTO_FIELD_DEFAULT(String, sequence, ZH_WORDS_GETTER("groupManagement.groupInfo.field.sequence"));
	////更新时间
	//API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("groupManagement.groupInfo.field.updateTime"));
	////分配因素
	//API_DTO_FIELD_DEFAULT(Int64, distributeFactor, ZH_WORDS_GETTER("groupManagement.groupInfo.field.distributeFactor"));
	////描述
	//API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("groupManagement.groupInfo.field.description"));
	////分配名
	//API_DTO_FIELD_DEFAULT(String, distinguishedName, ZH_WORDS_GETTER("groupManagement.groupInfo.field.distinguishedName"));
	////名字
	//API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("groupManagement.groupInfo.field.name"));
	////排名
	//API_DTO_FIELD_DEFAULT(Int64, orderNumber, ZH_WORDS_GETTER("groupManagement.groupInfo.field.orderNumber"));
	////拼音
	//API_DTO_FIELD_DEFAULT(String, pinyin, ZH_WORDS_GETTER("groupManagement.groupInfo.field.pinyin"));
	////初始化拼音
	//API_DTO_FIELD_DEFAULT(String, pinyinInitial, ZH_WORDS_GETTER("groupManagement.groupInfo.field.pinyinInitial"));
	////是否唯一
	//API_DTO_FIELD_DEFAULT(String, unique, ZH_WORDS_GETTER("groupManagement.groupInfo.field.unique"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_GetGroupInfoDTO_H_