#pragma once
#ifndef _FROM_DAO_H
#define _FROM_DAO_H
#include "BaseDAO.h"

#include "../../../domain/do/content/management/FormDO.h"
#include "../../../domain/dto/content/management/DeleteFormDTO.h"
/*
	删除表单数据库操作
*/
class FormDAO :public BaseDAO {
public:
	// 通过ID删除数据
	int deleteById(string id);
	//修改
	int update(const FormDO& uObj);
};

#endif // !_FROM_DAO_H
