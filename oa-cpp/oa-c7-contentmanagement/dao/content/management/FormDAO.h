#pragma once
#ifndef _FROM_DAO_H
#define _FROM_DAO_H
#include "BaseDAO.h"

#include "../../../domain/do/content/management/FormDO.h"
#include "../../../domain/dto/content/management/DeleteFormDTO.h"
/*
	ɾ�������ݿ����
*/
class FormDAO :public BaseDAO {
public:
	// ͨ��IDɾ������
	int deleteById(string id);
	//�޸�
	int update(const FormDO& uObj);
};

#endif // !_FROM_DAO_H
