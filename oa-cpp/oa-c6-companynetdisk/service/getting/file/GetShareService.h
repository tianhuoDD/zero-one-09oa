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
#include <list>
#include "domain/vo/getting/file/GetShareFilesVO.h"
#include "domain/query/getting/file/GetShareFilesQuery.h"
#include "domain/dto/getting/file/GetShareFilesDTO.h"
#include "domain/do/file/file_attachmentDO.h"

#include "domain/vo/getting/file/GetShareUsersVO.h"
#include "domain/query/getting/file/GetShareUsersQuery.h"
#include "domain/dto/getting/file/GetShareUsersDTO.h"
#include "domain/do/file/file_attachment_sharelistDO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetShareService
{
public:

	// ��ҳ��ѯ��������
	GetShareFilesPageDTO::Wrapper listAll_file(const GetShareFilesQuery::Wrapper& query);
	GetShareUsersPageDTO::Wrapper listAll_user(const GetShareUserQuery::Wrapper& query);
};

#endif // !_SHAREFILES_SERVICE_



