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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/attachment/AttachmentListVO.h"
#include "domain/vo/attachment/AttachmentDetailVO.h"
#include "domain/vo/attachment/AttachmentVO.h"
#include "domain/dto/attachment/AttachmentOperateDTO.h"


class AttachmentService
{
public:
	//获取所有附件
	AttachmentListVO::Wrapper listAll(const string& xapplication);
	//获取附件详情
	AttachmentDetailVO::Wrapper Detail(const string& xid);
	// 添加附件
	string saveFile(const AttachmentOperateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改附件
	bool updateFile(const AttachmentOperateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除附件
	string deleteFile(const string& xid);
};

#endif // !_SAMPLE_SERVICE_

