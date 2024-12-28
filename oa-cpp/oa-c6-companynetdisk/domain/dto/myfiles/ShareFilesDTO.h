#pragma once
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
#ifndef _SHAREFILESDTO_H_
#define _SHAREFILESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ShareFilesDTO : public oatpp::DTO
{
	DTO_INIT(ShareFilesDTO, DTO);
	//文件xid
	API_DTO_FIELD_DEFAULT(String, ATTACHMENT_XID, ZH_WORDS_GETTER("Myfile.filed.xid"))
		// 共享文件的用户id
		API_DTO_FIELD_DEFAULT(String, xshareList, ZH_WORDS_GETTER("Myfile.share.xid"))


		API_DTO_FIELD_DEFAULT(Int64, xorderColumn, ZH_WORDS_GETTER("Myfile.share.col"))

};



#include OATPP_CODEGEN_END(DTO)

#endif // !_SHAREFILESDTO_H_
