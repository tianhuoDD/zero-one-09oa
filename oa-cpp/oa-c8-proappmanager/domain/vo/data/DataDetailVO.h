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
#ifndef _DATACONFIGDETAILVO_H_
#define _DATACONFIGDETAILVO_H_
#include "../../GlobalInclude.h"
#include "domain/dto/data/DataDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DataDetailJsonVO : public JsonVO<DataDetailDTO::Wrapper> {
	DTO_INIT(DataDetailJsonVO, JsonVO<DataDetailDTO::Wrapper>);
};



///**
// * ��������������ʾ����
// */
//class DataDetailVO : public oatpp::DTO
//{
//	DTO_INIT(DataDetailVO, DTO);
//
//	// ��ϸ��Ϣ
//	API_DTO_FIELD_DEFAULT(String, data, ZH_WORDS_GETTER("config.detail.field.data"));
//
//	// ����Ψһ��ʶ��
//	API_DTO_FIELD_DEFAULT(String, dataid, ZH_WORDS_GETTER("config.detail.field.dataid"));
//
//	// ����
//	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("config.detail.field.name"));
//
//	// ����
//	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("config.detail.field.alias"));
//
//	// ������Ϣ
//	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("config.detail.field.description"));
//
//};
//
///**
// * ��������������ʾJsonVO��������Ӧ���ͻ��˵�Json����
// */
//class DataDetailJsonVO : public JsonVO<DataDetailVO::Wrapper> {
//	DTO_INIT(DataDetailJsonVO, JsonVO<DataDetailVO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DataConfigDetailVO_H_
