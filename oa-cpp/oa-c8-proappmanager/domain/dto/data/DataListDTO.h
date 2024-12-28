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
#ifndef _DATALIST_DTO_
#define _DATALIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class DataListDTO : public oatpp::DTO
{
	DTO_INIT(DataListDTO, DTO);

	// Ӧ��Ψһ��ʶ��
	API_DTO_FIELD_DEFAULT(String, appid, ZH_WORDS_GETTER("config.list.field.appid"));

	//����Ψһ��ʶ��
	API_DTO_FIELD_DEFAULT(String, dataid, ZH_WORDS_GETTER("config.list.field.dataid"));

	// Ӧ�ó���
	//API_DTO_FIELD_DEFAULT(String, application, ZH_WORDS_GETTER("config.list.field.application"));

	// ����������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("config.list.field.name"));

	// ����
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("config.list.field.alias"));

	// ������Ϣ
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("config.list.field.description"));

	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, creatTime, ZH_WORDS_GETTER("config.list.field.creatTime"));

	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("config.list.field.updateTime"));
};
class DataListPageDTO : public PageDTO<DataListDTO::Wrapper> {
	DTO_INIT(DataListPageDTO, PageDTO<DataListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DATALIST_DTO_
