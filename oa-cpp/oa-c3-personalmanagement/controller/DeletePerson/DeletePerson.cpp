#include"DeletePerson.h"
Uint64JsonVO::Wrapper DeletePersonController::execDeletePerson(const String& id) {
	 
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	 
	// ����һ��Service
	AddServe service;
	// ִ������ɾ��
	auto ans = service.removeData(string(id->c_str()));
	if (ans) {
		jvo->success(ans);
	}
	else
	{
		jvo->fail(ans);
	}
	// ��Ӧ���
	return jvo;
}