#pragma once
#ifndef _DELETE_SERVICE_
#define _DELETE_SERVICE_
#include <list>
#include "../../../domain/vo/Functional-permissions/Delete-menu/DeletemenuVO.h"
#include "../../../domain/dto/Functional-permissions/Delete-menu/DeletemenuDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DeletemenuService
{
public:
	// ��ҳ��ѯ��������
	uint64_t selectData(const DeletemenuDTO::Wrapper& dto);
	// ��������
	
	// �޸�����
	
	// ɾ������
	uint64_t removeData(const DeletemenuDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_