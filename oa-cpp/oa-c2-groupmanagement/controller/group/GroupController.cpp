#include "stdafx.h"
#include "GroupController.h"
//#include "../../service/group/GroupService.h"
#include "../ApiDeclarativeServicesHelper.h"

//StringJsonVO::Wrapper GroupController::execModifyGroup(const GroupDTO::Wrapper& dto)
//{
//	//// ���巵�����ݶ���
//	//auto jvo = Uint64JsonVO::createShared();
//	//// ����У��
//	//if (!dto->id || dto->id <= 0)
//	//{
//	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//	//	return jvo;
//	//}
//	//// ����һ��Service
//	//GroupService service;
//	//// ִ�������޸�
//	//if (service.updateData(dto)) {
//	//	jvo->success(dto->id);
//	//}
//	//else
//	//{
//	//	jvo->fail(dto->id);
//	//}
//	//// ��Ӧ���
//	//return jvo;
//	return {};
//}

StringJsonVO::Wrapper GroupController::executeModifyGroup(const GroupDTO::Wrapper& dto)
{
	return {};
}

UserPageJsonVO::Wrapper GroupController::executeQueryUser(const String& id)
{
	return {};
}
