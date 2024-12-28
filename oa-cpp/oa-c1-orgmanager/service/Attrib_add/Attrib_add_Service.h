#pragma once
#ifndef _ATTRIB_SERVICE_
#define _ATTRIB_SERVICE_
#include <list>
#include "domain/vo/Attrib_add/Attrib_add_VO.h"
#include "domain/dto/Attrib_add/Attrib_add_DTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Attrib_add_Service
{
public:
	//����id�Ƿ����
	uint64_t select_id(const Attrib_add_DTO::Wrapper& dto);

	// ��������
	uint64_t saveData1(const Attrib_add_DTO::Wrapper& dto);
	uint64_t saveData2(const Attrib_add_DTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

