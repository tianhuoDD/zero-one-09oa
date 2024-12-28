#include "stdafx.h"
#include "DeleteContentsController.h"
#include "../../service/contents/contentsservice.h"

StringJsonVO::Wrapper DeleteContentsController::execRemoveSample(const String& xid)
{
	//�������ݷ��ض���
	auto jvo = StringJsonVO::createShared();
	//����У��
	if (!xid)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		//jvo->fail(String("ParameterWrong"));
		return jvo;
	}
	//����һ��Service
	ContentsService service;
	//ִ������ɾ��
	if (service.removeContents(xid.getValue("1"))) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	return jvo;
}

StringJsonVO::Wrapper DeleteContentsController::execModifySample(const CdeleteDTO::Wrapper& dto, const PayloadDTO& payload)
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
	ContentsService service;
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


