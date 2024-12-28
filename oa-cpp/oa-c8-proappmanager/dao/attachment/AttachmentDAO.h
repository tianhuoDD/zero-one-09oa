#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/attachment/AttachmentDO.h"
#include "../../domain/do/attachment/AttachmentDetailDO.h"
#include "../../domain/do/attachment/AttachmentListDO.h"
#include "../../domain/vo/attachment/AttachmentVO.h"
#include "../../domain/vo/attachment/AttachmentListVO.h"
#include "../../domain/vo/attachment/AttachmentDetailVO.h"
#include "AttachmentDAO.h"
#include "AttachmentMapper.h"
/**
 * 示例表数据库操作实现
 */
class AttachmentDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const std::string& xapplication);
	// 查询所有数据
	list<AttachmentListDO> GetList(const std::string& xapplication);
	// 通过id查询唯一数据
	list<AttachmentDetailDO> selectByID(const std::string& id);
	// 保存附件信息
	int saveAttachment(const AttachmentDetailDO& attachment);
	// 修改附件信息
	int updateAttachment(const AttachmentDetailDO& attachment);
	// 删除附件信息
	int deleteAttachment(const std::string& id);
};
#endif // !_SAMPLE_DAO_
