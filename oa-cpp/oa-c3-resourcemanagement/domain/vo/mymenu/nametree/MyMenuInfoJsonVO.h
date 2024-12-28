#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/16 17:02:58

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
#ifndef _MENUINFOJSONVO_H_
#define _MENUINFOJSONVO_H_
#include "../../../GlobalInclude.h"
#include "../../../dto/mymenu/nametree/MyMenuInfoDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class MyMenuInfoJsonVO : public JsonVO<oatpp::data::mapping::type::List<MyMenuInfoDTO::Wrapper>>
{
	DTO_INIT(MyMenuInfoJsonVO, JsonVO<oatpp::data::mapping::type::List<MyMenuInfoDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	MyMenuInfoJsonVO() {
		this->data = {};
	}
};
class MyMenuInfoPageJsonVO : public JsonVO<oatpp::data::mapping::type::List<MyMenuInfoPageDTO::Wrapper>> {
	DTO_INIT(MyMenuInfoPageJsonVO, JsonVO< oatpp::data::mapping::type::List<MyMenuInfoPageDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	MyMenuInfoPageJsonVO() {
		this->data = {};
	}
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_