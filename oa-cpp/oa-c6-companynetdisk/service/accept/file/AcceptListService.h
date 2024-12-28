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
#ifndef _ACCEPTLIST_SERVICE_
#define _ACCEPTLIST_SERVICE_
#include <list>
#include "../../../domain/dto/accept/file/AcceptFileListDTO.h"
#include "../../../domain/dto/accept/file/AcceptUserListDTO.h"
#include "../../../domain/query/accept/file/AcceptFileListQuery.h"
#include "../../../domain/query/accept/file/AcceptUserListQuery.h"
#include "../../../domain/vo/accept/file/AcceptFileListVO.h"
#include "../../../domain/vo/accept/file/AcceptUserListVO.h"
#include "../../../domain/do/file/file_attachmentDO.h"
#include "../../../domain/do/file/file_attachment_editorlistDO.h"




/**
 * 示例服务实现，演示基础的示例服务实现
 */
 //获取文件了列表
class AcceptListService
{
public:
	// 分页查询所有数据
	AcceptFilesPageDTO::Wrapper file_listAll(const AcceptFileListQuery::Wrapper& query);
	AcceptUsersPageDTO::Wrapper user_listAll(const AcceptUserListQuery::Wrapper& query);
};


#endif // !_SAMPLE_SERVICE_
