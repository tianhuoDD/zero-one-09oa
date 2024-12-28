#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/18 15:01:29

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
#ifndef _GETShareUsersDTO_H_
#define _GETShareUsersDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 共享用户列表传输数据对象
 */
class GetShareUsersDTO : public oatpp::DTO
{
	DTO_INIT(GetShareUsersDTO, DTO);
	//文件id
	API_DTO_FIELD(String, ATTACHMENT_XID, ZH_WORDS_GETTER("Myfile.file.id"), false, "admis");
	//文件上传人
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.filed.xperson"), false, "admis");

};
/**
 * 共享用户列表分页传输数据对象
 */

class GetShareUsersPageDTO : public PageDTO<GetShareUsersDTO::Wrapper>
{
	DTO_INIT(GetShareUsersPageDTO, PageDTO<GetShareUsersDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_GETShareUsersDTO_H_