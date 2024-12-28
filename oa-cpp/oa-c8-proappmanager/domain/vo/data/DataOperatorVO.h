#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _DATAOPERATOR_VO_
#define _DATAOPERATOR_VO_

#include "domain/GlobalInclude.h"
#include"domain/dto/data/DataOperatorDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������������ʾ����
 */
class DataOperatorVO : public oatpp:: DTO {
	DTO_INIT(DataOperatorVO, JsonVO<DataOperatorDTO::Wrapper>);

	//��������id
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"), true, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"));

	//����������id
	API_DTO_FIELD_DEFAULT(String, itemid, ZH_WORDS_GETTER("dataconfiguration.item.item-id"));

	//����������������(��ʾ)
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("dataconfiguration.datamessage.name"));

	//�����������ñ���(��ʾ)
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("dataconfiguration.datamessage.alias"));


	//���������������к�
	API_DTO_FIELD_DEFAULT(String, sequence, ZH_WORDS_GETTER("dataconfiguration.datamessage.sequence"));

	//�������÷�������
	API_DTO_FIELD_DEFAULT(UInt64, distributefactor, ZH_WORDS_GETTER("dataconfiguration.datamessage.distributefactor"));
};

/**
 * �����������õ���Ӧ����ǰ��
 */
class DataOperatorJsonVo : public JsonVO<DataOperatorVO::Wrapper> {
	DTO_INIT(DataOperatorJsonVo, JsonVO<DataOperatorVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DATAOPERATOR_VO_