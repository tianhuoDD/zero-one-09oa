#pragma once
#ifndef _MODIFY_LOCKORUNLOCK_OFFICERSERVICE_
#define _MODIFY_LOCKORUNLOCK_OFFICERSERVICE_

#include <list>
#include "../../domain/dto/modify/modify_lockorunlock_officerDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class modify_lockorunlock_officerService
{
public:

	// �޸�����
	bool updateData(const modify_lockorunlock_officerDTO::Wrapper& dto);

};











#endif // !_MODIFY_LOCKORUNLOCK_OFFICERSERVICE_
