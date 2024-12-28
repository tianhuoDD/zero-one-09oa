#include "stdafx.h"
#include "AdminPwdController.h"
#include "../../../service/password/admin/adminPwdService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/password/AdminPwdService.h"

#define RS_NEW_PASSWORD_SAME_AS_OLD ResultStatus(u8"新旧密码应不同",9993)
#define RS_NEW_PASSWORD_CONFIRM_MISMATCH ResultStatus(u8"确认密码错误",9992)



AdminPwdJsonVO::Wrapper AdminPwdController::executeQueryAdminPwd(const String& xid)
{
	
	// 定义一个Service
	AdminPwdService service;
	// 查询数据
	auto result = service.listAll(xid);
	// 响应结果
	auto jvo = AdminPwdJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper AdminPwdController::executeModifyAdminPwd(const AdminPwdDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

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
	// 定义一个Service
	adminPwdService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// 响应结果
	return jvo;
}
