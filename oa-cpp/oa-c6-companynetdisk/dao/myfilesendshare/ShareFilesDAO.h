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
#ifndef _SHAREFILES_DAO_
#define _SHAREFILES_DAO_
#include "BaseDAO.h"
#include"../../domain/do/file/file_attachment_sharelistDO.h"
#include"../../domain/do/file/file_operation_logDO.h"
class ShareFilesDAO : public BaseDAO
{
public:
	uint64_t insert(const file_attachment_sharelistDO& iObj);
	uint64_t insertsharelog(const FileLogDO& iObj);
};

#endif // !_SHAREFILES_DAO_
