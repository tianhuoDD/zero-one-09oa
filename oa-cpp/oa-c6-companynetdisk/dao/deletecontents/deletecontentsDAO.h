#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/folder/file_folderDO.h"


class contentsDAO : public BaseDAO
{
public:

	// �޸�����
	int update(const file_folderDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string xid);
};
#endif // !_SAMPLE_DAO_