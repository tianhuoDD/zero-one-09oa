#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/resource-management/resource-tree-permissions/ResourcetreeVO.h"
#include "domain/query/resource-management/Resourcetreequery.h"
#include "dao/resource-tree-permissios/ResourcetreeDAO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ResourcetreeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ResourcetreeController);
	// 3 ����ӿ�
public:
	// �����ѯ�û��˵��ӿڶ˵�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("resource.get.permissions"), queryMenu, PermissionsJsonVO::Wrapper);
	// �����ѯ�û��˵��ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "resource-management/resource-tree-permissions", queryMenu, executeQuerypermissions(authObject->getPayload()))
private:
	// ִ�л�ȡ������Ϣ
	PermissionsJsonVO::Wrapper executeQuerypermissions(const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_