#include "OrgStructController.h"
#include "stdafx.h"
//����service�ļ�
#include "../../service/OrgStructService/OrgStructService.h"
#include<iostream>
#define Max 1844674

//����OrgStructListJsonVO��������
OrgStructPageJsonVO::Wrapper OrgStructController::executeQueryOrgStruct(const OrgStructPageQuery::Wrapper& condtion)
{
	// 1. ���巵�����ݶ���
	auto res = OrgStructPageJsonVO::createShared();

	////���ش����ѯ��Ϣ
	if (condtion->pageIndex >= Max || condtion->pageSize >= Max)
	{
		//������벻�Ϸ��򷵻�null
		return res;
	}
	
	// ����һ��Service (�����ݴ��ݸ�service��)
	OrgStructService service;
	auto result = service.listAll(condtion);

	//ִ�����ݲ�ѯ
	res->success(result);

	// ��Ӧ���
	return res;
}

/*
	���ܣ�
	������const OrgStructPageQuery::Wrapper& condtion ΪQuery ʵ�ʼ̳���DTO
	����ֵ��void
*/
OrgStaffPageJsonVO::Wrapper OrgStructController::executeQueryOrgStaff(const OrgStaffPageQuery::Wrapper& condtion)
{
	auto res = OrgStaffPageJsonVO::createShared();

	std::cout << condtion->pageIndex.getValue({}) << " " << condtion->Pinyin.getValue({}) << " " << condtion->Pinyin.getValue({})
		<< condtion->xmobile.getValue({});

	////���ش����ѯ��Ϣ
	if (condtion->pageIndex >= Max || condtion->pageSize >= Max)
	{
		//������벻�Ϸ��򷵻�null
		return res;
	}
	OrgStaffService service;
	auto result = service.list(condtion);

	res->success(result);

	return res;
}