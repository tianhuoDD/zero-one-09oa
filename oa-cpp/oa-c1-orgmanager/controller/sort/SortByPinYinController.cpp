#include "stdafx.h"
#include "SortByPinYinController.h"
//#include "../../service/sample/SampleService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "SortByPinYinController.h"
#include "../../service/Sort/SortByPinYinService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "SortByPinYinController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/Sort/SortByPinYinDO.h"
#include "service/Sort/SortByPinYinService.h"
#include "dao/Sort/SortByPinYinDAO.h"  // ����DAO

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


//�����ݽ��г�������
SortByPinYinPageJsonVO::Wrapper SortByPinYinController::execQuerySortByPinYin(const SortByPinYinQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	SortByPinYinService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = SortByPinYinPageJsonVO::createShared();

	jvo->success(result);

	return jvo;
}