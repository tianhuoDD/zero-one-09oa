#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 1:58:52

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
#ifndef _DELETEGROUPVO_H_
#define _DELETEGROUPVO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 删除群组的主键显示对象
 */
class DeleteGroupVO : public oatpp::DTO
{
	DTO_INIT(DeleteGroupVO, DTO);
	//群组唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"));
};


/**
 * 群组删除主键显示JsonVO，用于响应给客户端的Json对象
 */
class DeleteGroupJsonVO : public JsonVO<DeleteGroupVO::Wrapper> {
	DTO_INIT(DeleteGroupJsonVO, JsonVO<DeleteGroupVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETEGROUPVO_H_