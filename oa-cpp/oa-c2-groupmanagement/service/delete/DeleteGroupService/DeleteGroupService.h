#pragma once
#ifndef _DELETEGROUPSERVICE_H_
#define _DELETEGROUPSERVICE_H_


#include "../../../domain/dto/delete/DeleteGroupDTO/DeleteGroupDTO.h"
#include "../../../domain/vo/delete/DeleteGroup/DeleteGroupVO.h"
#include "../../../dao/delete/DeleteGroup/DeleteGroupDAO.h"

class DeleteGroupService
{
public:
	// ͨ��IDɾ������
	bool removeData(string id);

};

#endif // !_DELETEGROUPSERVICE_H_