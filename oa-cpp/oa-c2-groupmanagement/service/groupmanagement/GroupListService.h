#pragma once

#ifndef _GROUPLIST_SERVICE_
#define _GROUPLIST_SERVICE_
#include <list>
#include "domain/vo/get/GroupListVO.h"
#include "domain/query/get/GroupListQuery.h"
#include "domain/dto/get/GroupListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GroupListService
{
public:
	// ��ҳ��ѯ��������
	GroupListPageDTO::Wrapper listAll(const GroupListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const GroupListDTO::Wrapper& dto);
	//// �޸�����
	//bool updateData(const SampleDTO::Wrapper& dto);
	//// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

