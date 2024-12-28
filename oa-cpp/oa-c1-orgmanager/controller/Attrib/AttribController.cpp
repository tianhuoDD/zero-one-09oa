/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "AttribController.h"
#include "../../service/Attrib/AttribService.h"
#include "../ApiDeclarativeServicesHelper.h"

//�����ݽ��г�������
AttribPageJsonVO::Wrapper AttribController::execQueryAttrib(const AttribQuery::Wrapper& query)//, const PayloadDTO& payload
{
	// ����һ��Service
	AttribService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = AttribPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper AttribController::execAddAttrib(const AttribDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->name || !dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	/*if (dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	// ����һ��Service
	AttribService service;
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

Uint64JsonVO::Wrapper AttribController::execModifyAttrib(const AttribDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	AttribService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

//Uint64JsonVO::Wrapper AttribController::execRemoveAttrib(const UInt64& id)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	AttribService service;
//	// ִ������ɾ��
//	if (service.removeData(id.getValue(0))) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// ��Ӧ���
//	return jvo;
//}

//SampleJsonVO::Wrapper SampleController::execQueryOne(const UInt64& id, const PayloadDTO& payload)
//{
//	// �����ͻ��˶���
//	API_CLIENT_CREATE(ac, om, SampleApiClient, "sample-api");
//	// ����ƾ֤
//	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//	// ���ز�ѯ���
//	return ac->queryById(token, id)->readBodyToDto<SampleJsonVO::Wrapper>(om);
//}
//
//SamplePageJsonVO::Wrapper SampleController::execQueryAll(const SampleQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// �����ͻ��˶���
//	API_CLIENT_CREATE(ac, om, SampleApiClient, "sample-api");
//	// ����ƾ֤
//	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//	// ���ز�ѯ���
//	return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->name))->readBodyToDto<SamplePageJsonVO::Wrapper>(om);
//}