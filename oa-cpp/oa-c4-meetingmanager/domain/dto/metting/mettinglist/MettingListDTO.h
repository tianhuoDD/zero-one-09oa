#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MettingList_DTO_
#define _MettingList_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class MettingListDTO : public oatpp::DTO
{
	DTO_INIT(MettingListDTO, DTO);

	// 申请人
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("query.metting.mettingList.applyname"));

	// 日期
	API_DTO_FIELD_DEFAULT(String, date1, ZH_WORDS_GETTER("query.metting.mettingList.date"));

	// starttime
	API_DTO_FIELD_DEFAULT(String, timestart, ZH_WORDS_GETTER("query.metting.mettingList.timestart"));

	// endtime
	API_DTO_FIELD_DEFAULT(String, timeend, ZH_WORDS_GETTER("query.metting.mettingList.timeend"));

	// 标题
	API_DTO_FIELD_DEFAULT(String, title1, ZH_WORDS_GETTER("query.metting.mettingList.title"));

	// 会议室
	API_DTO_FIELD_DEFAULT(String, mettingroom, ZH_WORDS_GETTER("query.metting.mettingList.metting"));
};

/**
 * 示例分页传输对象
 */
class MettingListPageDTO : public PageDTO<MettingListDTO::Wrapper>
{
	DTO_INIT(MettingListPageDTO, PageDTO<MettingListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MettingList_DTO_