#include "DeleteGroupService.h"



bool DeleteGroupService::removeData(string id)
{
	//先创建一个dao
	DeleteGroupDAO dao;
	return dao.deleteById(id) == 1;
}
