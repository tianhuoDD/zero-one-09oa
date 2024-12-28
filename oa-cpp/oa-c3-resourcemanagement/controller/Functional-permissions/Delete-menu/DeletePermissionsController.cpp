#include "stdafx.h"
#include "DeletePermissionsController.h"
#include "../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../lib-oatpp/include/domain/vo/JsonVO.h"
#include "../../../service/Functional-permissions/Delete-menu/DeletemenuService.h"

DeletemenuJsonVO::Wrapper DeletePermissionsController:: execDeletemenu(const DeletemenuDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = DeletemenuJsonVO::createShared();
	auto vodto =DeletemenuVO::createShared();
	
	// ����У��
	if (dto->role_id->empty() || dto->permissions->empty())
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	// ����һ��Service
	//�ж���Ҫɾ����ֵ�Ƿ����
	DeletemenuService service;
	uint64_t count = service.selectData(dto);
	if (count <= 0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ִ������ɾ��
	if (service.removeData(dto)>0) {
		vodto->role_id = dto->role_id;
		auto permissionslist = dto->permissions;
	vodto->permissions= oatpp::List<String>::createShared(); // ����һ���µ��б�
		for (const auto& permission : *permissionslist)
		{
			vodto->permissions->push_back(permission);
			
		}
		jvo->success(vodto);
	}
	else
	{
		jvo->fail(vodto);
	}
	// ��Ӧ���
	return jvo;
	
}