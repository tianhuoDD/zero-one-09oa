#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/12/03 11:01:02

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
#ifndef _UPDATEATTACHMNETQUERY_H_
#define _UPDATEATTACHMNETQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class UpdateAttachmentQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(UpdateAttachmentQuery, PageQuery);
	// 昵称
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("productionorder.query.fields.xid"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATEATTACHMNETQUERY_H_