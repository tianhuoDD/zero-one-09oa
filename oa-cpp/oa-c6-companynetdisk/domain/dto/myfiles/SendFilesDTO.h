#pragma once

/*
Copyright Zero One Star. All rights reserved.

@Author: awei
@Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$

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
#ifndef _SENDFILESDTO_H_
#define _SENDFILESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendFilesDTO : public oatpp::DTO
{
	DTO_INIT(SendFilesDTO, DTO);

	//文件id
	API_DTO_FIELD_DEFAULT(String, ATTACHMENT_XID, ZH_WORDS_GETTER("Myfile.filed.xid"))

		// 发送文件的用户id
		API_DTO_FIELD_DEFAULT(String, xeditorList, ZH_WORDS_GETTER("Myfile.send.xid"))

		API_DTO_FIELD_DEFAULT(Int64, xorderColumn, ZH_WORDS_GETTER("Myfile.send.col"))


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SENDFILESDTO_H_
