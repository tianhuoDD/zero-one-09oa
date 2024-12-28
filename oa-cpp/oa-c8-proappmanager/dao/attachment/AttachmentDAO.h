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
 * ʾ�������ݿ����ʵ��
 */
class AttachmentDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const std::string& xapplication);
	// ��ѯ��������
	list<AttachmentListDO> GetList(const std::string& xapplication);
	// ͨ��id��ѯΨһ����
	list<AttachmentDetailDO> selectByID(const std::string& id);
	// ���渽����Ϣ
	int saveAttachment(const AttachmentDetailDO& attachment);
	// �޸ĸ�����Ϣ
	int updateAttachment(const AttachmentDetailDO& attachment);
	// ɾ��������Ϣ
	int deleteAttachment(const std::string& id);
};
#endif // !_SAMPLE_DAO_
