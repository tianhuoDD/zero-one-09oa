#include "OrgStructController.h"
#include "stdafx.h"
//引入service文件
#include "../../service/OrgStructService/OrgStructService.h"
#include<iostream>
#define Max 1844674

//返回OrgStructListJsonVO类型数据
OrgStructPageJsonVO::Wrapper OrgStructController::executeQueryOrgStruct(const OrgStructPageQuery::Wrapper& condtion)
{
	// 1. 定义返回数据对象
	auto res = OrgStructPageJsonVO::createShared();

	////拦截错误查询信息
	if (condtion->pageIndex >= Max || condtion->pageSize >= Max)
	{
		//如果输入不合法则返回null
		return res;
	}
	
	// 定义一个Service (将数据传递给service端)
	OrgStructService service;
	auto result = service.listAll(condtion);

	//执行数据查询
	res->success(result);

	// 响应结果
	return res;
}

/*
	功能：
	参数：const OrgStructPageQuery::Wrapper& condtion 为Query 实际继承与DTO
	返回值：void
*/
OrgStaffPageJsonVO::Wrapper OrgStructController::executeQueryOrgStaff(const OrgStaffPageQuery::Wrapper& condtion)
{
	auto res = OrgStaffPageJsonVO::createShared();

	std::cout << condtion->pageIndex.getValue({}) << " " << condtion->Pinyin.getValue({}) << " " << condtion->Pinyin.getValue({})
		<< condtion->xmobile.getValue({});

	////拦截错误查询信息
	if (condtion->pageIndex >= Max || condtion->pageSize >= Max)
	{
		//如果输入不合法则返回null
		return res;
	}
	OrgStaffService service;
	auto result = service.list(condtion);

	res->success(result);

	return res;
}