#pragma once
#ifndef _MODIFYGROUPINFO_SERVICE_
#define _MODIFYGROUPINFO_SERVICE_
#include <list>
#include "domain/vo/group/GroupVO.h"
#include "domain/dto/group/GroupDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ModifyGroupInfoService
{
public:
	//// ��ҳ��ѯ��������
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	// ��������
	//uint64_t saveData(const GroupDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const GroupDTO::Wrapper& dto);
};

#endif // !_MODIFYGROUPINFO_SERVICE_
