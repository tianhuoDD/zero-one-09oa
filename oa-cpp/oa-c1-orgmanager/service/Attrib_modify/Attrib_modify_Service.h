#pragma once
#ifndef _ATTRIB_SERVICE_
#define _ATTRIB_SERVICE_
#include <list>
#include "domain/vo/Attrib_modify/Attrib_modify_VO.h"
#include "domain/dto/Attrib_modify/Attrib_modify_DTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Attrib_modify_Service
{
public:
	//����id�Ƿ����
	uint64_t select_id(const Attrib_modify_DTO::Wrapper& dto);

	// �޸�����
	bool updateData(const Attrib_modify_DTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

