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
#include "dao/Sort/SortByPinYinDAO.h"  // 导入DAO

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


//对数据进行初步处理
SortByPinYinPageJsonVO::Wrapper SortByPinYinController::execQuerySortByPinYin(const SortByPinYinQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	SortByPinYinService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = SortByPinYinPageJsonVO::createShared();

	jvo->success(result);

	return jvo;
}