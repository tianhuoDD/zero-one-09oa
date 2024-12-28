#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 20:24:54

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
#ifndef _GetGROUPINFOVO_H_
#define _GetGROUPINFOVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/get/GetGroupInfoDTO/GetGroupInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 群组信息显示对象
 */
class GetGroupInfoVO : public oatpp::DTO
{
	DTO_INIT(GetGroupInfoVO, DTO);
	//名字
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("groupManagement.groupInfo.field.name"), false, "errorrrrrrrrrrr");
	//群组唯一标识
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), true, "errorrrrrrrrrrr");
	//描述
	API_DTO_FIELD(String, description, ZH_WORDS_GETTER("groupManagement.groupInfo.field.description"), false, "errorrrrrrrrrrr");

	////群组唯一标识
	//API_DTO_FIELD(String, id, ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), true, "1qdxwq2w");
	////创建时间
	//API_DTO_FIELD(String, createTime, ZH_WORDS_GETTER("groupManagement.groupInfo.field.createTime"), true, "2023.10.24");
	////序列
	//API_DTO_FIELD(String, sequence, ZH_WORDS_GETTER("groupManagement.groupInfo.field.sequence"), false, "57-1234");
	////更新时间
	//API_DTO_FIELD(String, updateTime, ZH_WORDS_GETTER("groupManagement.groupInfo.field.updateTime"), true, "2024.10.20");
	////分配因素
	//API_DTO_FIELD(UInt64, distributeFactor, ZH_WORDS_GETTER("groupManagement.groupInfo.field.distributeFactor"), false, 1234);
	////描述
	//API_DTO_FIELD(String, description, ZH_WORDS_GETTER("groupManagement.groupInfo.field.description"), false, "hhh");
	////分配名
	//API_DTO_FIELD(String, distinguishedName, ZH_WORDS_GETTER("groupManagement.groupInfo.field.distinguishedName"), false, "02-bubian");
	////名字
	//API_DTO_FIELD(String, name, ZH_WORDS_GETTER("groupManagement.groupInfo.field.name"), false, "c2小组");
	////排名
	//API_DTO_FIELD(UInt64, orderNumber, ZH_WORDS_GETTER("groupManagement.groupInfo.field.orderNumber"), false, 98);
	////拼音
	//API_DTO_FIELD(String, pinyin, ZH_WORDS_GETTER("groupManagement.groupInfo.field.pinyin"), false, "c2xiaozu");
	////初始化拼音
	//API_DTO_FIELD(String, pinyinInitial, ZH_WORDS_GETTER("groupManagement.groupInfo.field.pinyinInitial"), false, "cppxiaozu");
	////是否唯一
	//API_DTO_FIELD(String, unique, ZH_WORDS_GETTER("groupManagement.groupInfo.field.unique"), false, "false");

};


/**
 * 群组信息显示JsonVO，用于响应给客户端的Json对象
 */
class GetGroupInfoJsonVO : public JsonVO<GetGroupInfoVO::Wrapper> {
	DTO_INIT(GetGroupInfoJsonVO, JsonVO<GetGroupInfoVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_GetGROUPINFOVO_H_