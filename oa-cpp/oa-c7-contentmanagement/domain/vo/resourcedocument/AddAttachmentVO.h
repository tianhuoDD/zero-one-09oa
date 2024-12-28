﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
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
#ifndef _AddAttachmentVO_H_
#define _AddAttachmentVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/resourcedocument/AddAttachmentDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class AddAttachmentJsonVO : public JsonVO<AddAttachmentDTO::Wrapper>
{
	DTO_INIT(AddAttachmentJsonVO, JsonVO<AddAttachmentDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // _AddAttachmentVO_H_