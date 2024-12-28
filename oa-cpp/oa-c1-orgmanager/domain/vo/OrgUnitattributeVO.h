#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: UptoFate
 @Date: 2024/10/21 21:47:08
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
#ifndef _ORGUNITATTRIBUTE_VO_H_
#define _ORGUNITATTRIBUTE_VO_H_
#include "../GlobalInclude.h"
#include "domain/dto/OrgUnitattributeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class OrgUnitattributeJsonVO : public JsonVO<OrgUnitattributeDTO::Wrapper>
{
	DTO_INIT(OrgUnitattributeJsonVO, JsonVO<OrgUnitattributeDTO::Wrapper>);
};
/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class OrgUnitattributePageJsonVO : public JsonVO<OrgUnitattributePageDTO::Wrapper>
{
	DTO_INIT(OrgUnitattributePageJsonVO, JsonVO<OrgUnitattributePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // _ORGUNITATTRIBUTE_VO_H_