#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/folder/file_deleteDO.h"


class deletefileDAO : public BaseDAO
{
public:

	// 
	int update(const file_deleteDO& uObj);

};
#endif // !_SAMPLE_DAO_
