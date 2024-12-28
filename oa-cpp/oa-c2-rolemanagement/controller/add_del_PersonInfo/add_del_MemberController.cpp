#include"stdafx.h"
#include "add_del_MemberController.h"

Uint64JsonVO::Wrapper add_del_MemberController::execAddMember(const MemberDTO::Wrapper& dto)
{

	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 定义一个Service
	MemberService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper add_del_MemberController::execRemoveMember(const UInt64& id)
{

	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 定义一个Service
	MemberService service;
	// 执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
	return Uint64JsonVO::Wrapper();
}
