#include "DeleteGroupService.h"



bool DeleteGroupService::removeData(string id)
{
	//�ȴ���һ��dao
	DeleteGroupDAO dao;
	return dao.deleteById(id) == 1;
}
