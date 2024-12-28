#include"stdafx.h"
#include "add_del_MemberController.h"

Uint64JsonVO::Wrapper add_del_MemberController::execAddMember(const MemberDTO::Wrapper& dto)
{

	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ����һ��Service
	MemberService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper add_del_MemberController::execRemoveMember(const UInt64& id)
{

	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	MemberService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
	return Uint64JsonVO::Wrapper();
}
