 /*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
 @Date: 2024/10/19 11:47:15

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
#ifndef _PERSONINFOVO_H_
#define _PERSONINFOVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Person/PersonInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PersonInfoPageJsonVO: public JsonVO<PersonInfoPageDTO::Wrapper> {
	DTO_INIT(PersonInfoPageJsonVO, JsonVO<PersonInfoPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PERSONINFOVO_H_