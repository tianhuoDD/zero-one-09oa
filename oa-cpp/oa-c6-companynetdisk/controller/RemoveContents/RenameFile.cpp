#include "stdafx.h"
#include "RenameFile.h"
#include "../../service/contents/fileservice.h"

StringJsonVO::Wrapper RenameFileController::execModifySample(const DdeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//����У��
	if (!dto->xid)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����service
	FileService service;
	//ִ�������޸�

	if (service.updateContents(dto))
	{
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// ��Ӧ���
	return jvo;
}
