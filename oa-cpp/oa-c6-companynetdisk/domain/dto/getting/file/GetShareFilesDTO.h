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
#ifndef _GETSHAREFILESDTO_H_
#define _GETSHAREFILESDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 共享文件列表传输数据对象
 */
class GetShareFilesDTO : public oatpp::DTO
{
	DTO_INIT(GetShareFilesDTO, DTO);
	//用户名字
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.filed.xperson"), false, "admis");
	//文件名
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.filed.xname"), false, "hhh");
	//文件大小
	API_DTO_FIELD(Int64, xlength, ZH_WORDS_GETTER("Myfile.file.size"), false, 1);
	//文件创建时间
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("getting.filed.xcreateTime"), false, "2024-10-24 16:43:24");
	//文件修改时间
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("getting.filed.xupdateTime"), false, "2024-10-24 16:43:24");

};
/**
 * 共享文件列表分页传输数据对象
 */

class GetShareFilesPageDTO : public PageDTO<GetShareFilesDTO::Wrapper>
{
	DTO_INIT(GetShareFilesPageDTO, PageDTO<GetShareFilesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETSHAREFILESDTO_H_