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
 * �����ļ��б������ݶ���
 */
class GetShareFilesDTO : public oatpp::DTO
{
	DTO_INIT(GetShareFilesDTO, DTO);
	//�û�����
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.filed.xperson"), false, "admis");
	//�ļ���
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.filed.xname"), false, "hhh");
	//�ļ���С
	API_DTO_FIELD(Int64, xlength, ZH_WORDS_GETTER("Myfile.file.size"), false, 1);
	//�ļ�����ʱ��
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("getting.filed.xcreateTime"), false, "2024-10-24 16:43:24");
	//�ļ��޸�ʱ��
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("getting.filed.xupdateTime"), false, "2024-10-24 16:43:24");

};
/**
 * �����ļ��б��ҳ�������ݶ���
 */

class GetShareFilesPageDTO : public PageDTO<GetShareFilesDTO::Wrapper>
{
	DTO_INIT(GetShareFilesPageDTO, PageDTO<GetShareFilesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETSHAREFILESDTO_H_