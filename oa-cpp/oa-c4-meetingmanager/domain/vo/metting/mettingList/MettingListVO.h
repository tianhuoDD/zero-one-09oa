#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _MettingListVO_H_
#define _MettingListVO_H_

#include "../../../GlobalInclude.h"
#include "domain/dto/metting/mettinglist/MettingListDTO.h" //��֪���Ƿ�������

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class MettingListJsonVO : public JsonVO<MettingListDTO::Wrapper>
{
	DTO_INIT(MettingListJsonVO, JsonVO<MettingListDTO::Wrapper>);

	// ������
	//API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("query.metting.mettingList.applyname"));

	// ����
	//API_DTO_FIELD_DEFAULT(String, date1, ZH_WORDS_GETTER("query.metting.mettingList.date"));

	// starttime
	//API_DTO_FIELD_DEFAULT(String, timestart, ZH_WORDS_GETTER("query.metting.mettingList.timestart"));

	// endtime
	//API_DTO_FIELD_DEFAULT(String, timeend, ZH_WORDS_GETTER("query.metting.mettingList.timeend"));

	// ����
	//API_DTO_FIELD_DEFAULT(String, title1, ZH_WORDS_GETTER("query.metting.mettingList.title"));

	// ������
	//API_DTO_FIELD_DEFAULT(String, mettingroom, ZH_WORDS_GETTER("query.metting.mettingList.metting"));
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class MettingListPageJsonVO : public JsonVO<MettingListPageDTO::Wrapper>
{
	DTO_INIT(MettingListPageJsonVO, JsonVO<MettingListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _MettingListVO_H_