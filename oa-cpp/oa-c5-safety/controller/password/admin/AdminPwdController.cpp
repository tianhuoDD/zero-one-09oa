#include "stdafx.h"
#include "AdminPwdController.h"
#include "../../../service/password/admin/adminPwdService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/password/AdminPwdService.h"

#define RS_NEW_PASSWORD_SAME_AS_OLD ResultStatus(u8"�¾�����Ӧ��ͬ",9993)
#define RS_NEW_PASSWORD_CONFIRM_MISMATCH ResultStatus(u8"ȷ���������",9992)



AdminPwdJsonVO::Wrapper AdminPwdController::executeQueryAdminPwd(const String& xid)
{
	
	// ����һ��Service
	AdminPwdService service;
	// ��ѯ����
	auto result = service.listAll(xid);
	// ��Ӧ���
	auto jvo = AdminPwdJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper AdminPwdController::executeModifyAdminPwd(const AdminPwdDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	if (dto->xoldpassword == dto->xnewpassword)
	{
		jvo->init(UInt64(-1), RS_NEW_PASSWORD_SAME_AS_OLD);
		return jvo;
	}
	if (dto->xnewpassword != dto->xconfirmpassword)
	{
		jvo->init(UInt64(-1), RS_NEW_PASSWORD_CONFIRM_MISMATCH);
		return jvo;
	}
	if (dto->xconfirmpassword->empty() || dto->xnewpassword->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	adminPwdService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// ��Ӧ���
	return jvo;
}
