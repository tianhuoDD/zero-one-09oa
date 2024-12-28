#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _SHAREFILES_SERVICE_
#define _SHAREFILES_SERVICE_
#include "../../domain/dto/myfiles/ShareFilesDTO.h"
#include "../../domain/dto/myfile/FilelogDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ShareFilesService
{
public:
	// ��ҳ��ѯ��������
	//ShareFilesDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ShareFilesDTO::Wrapper& dto);
	uint64_t insertShareLog(const FileLogDTO::Wrapper& ddto);
	// �޸�����
	//bool updateData(const SampleDTO::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_SHAREFILES_SERVICE_

