#include "stdafx.h"
#include "AddPermissionsController.h"
#include "../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../lib-oatpp/include/domain/vo/JsonVO.h"
#include "../../../controller/ApiDeclarativeServicesHelper.h"
#include "../../../service/Functional-permissions/Add-menu/AddmenuService.h"


AddmenuJsonVO::Wrapper AddPermissionsController:: execAddmenu(const AddmenuDTO::Wrapper& dto)
{
	auto jvo = AddmenuJsonVO::createShared();
	auto vodto = AddmenuVO::createShared();
	// ����У��
    //�о��ö������id�͹����Ƿ���ڽ���У�飬����û�й�����������Ȳ�����
	//��Ҫ�õ���Ա�������˵ı�ţ�����Ҫ�˵����ж�����Ĳ˵�Ȩ���Ƿ����
	if (dto->role_id->empty() || dto->permissions->empty())
	{
		
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	
	// ����һ��Service
	 //�о��ö������id�͹����Ƿ���ڽ���У�飬����û�й�����������Ȳ�����
	//��Ҫ�õ���Ա�������˵ı�ţ�����Ҫ�˵����ж�����Ĳ˵�Ȩ���Ƿ����
	AddmenuService service;
	if (service.selectDatabyrole_id(dto)<=0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	if (service.selectDatabypermissions(dto) <= 0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	
	if (service.selectDataisexist(dto) > 0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	// ִ����������
	//����������Ŵ�����������

	uint64_t id = service.saveData(dto);

	if (id == 0)
	{
		vodto->role_id = dto->role_id;
		vodto->permissions = dto->permissions;
		jvo->success(vodto);

	}
	else
	{
		jvo->fail(vodto);
	}
	
	
	//��Ӧ���
	
	return jvo;
	
}
