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
#include "OrgMemController.h"
#include "../service/OrgMemService.h"
#include "ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper OrgMemController::execAddOrgMem(const OrgMemDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	List<String> ids = dto->ids;
	string orgID = dto->orgID;
	// ����У��
	// �ǿ�У��
	if (!ids)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	/*// ��ЧֵУ��
	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	// ����һ��Service
	OrgMemService service;
	// ִ����������
	//uint64_t id = service.saveData(id);
	for (int i = 0; i < ids.get()->size(); i++) {
		string id = ids[i];

		// ����һ��Service
		OrgMemService service;
		if (service.addData(orgID, id)) {
			jvo->success(i);
		}
		else
		{
			jvo->fail(i);
		}
		jvo->success(i);
	}
	//��Ӧ���
	return jvo;
}
Uint64JsonVO::Wrapper OrgMemController::execRemoveOrgMem(const OrgMemDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	List<String> ids = dto->ids;
	string orgID = dto->orgID;
	// ����У��
	if (!ids)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OrgMemService service;
	// ִ������ɾ��
	for (int i = 0; i < ids.get()->size(); i++) {
		string id = ids[i];
		
		// ����һ��Service
		OrgMemService service;
		// ִ������ɾ��
		if (service.removeData(orgID, id)) {
			jvo->success(i);
		}
		else
		{
			jvo->fail(i);
		}
	}
	return jvo;
}
Uint64JsonVO::Wrapper OrgMemController::execRemoveJobMem(const string& personID,const string& dutyID) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	OrgJobService service;
	// ִ������ɾ��
	if (service.removeData(personID,dutyID)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	// ��Ӧ���
	return jvo;
}
Uint64JsonVO::Wrapper OrgMemController::execAddJobMem(const string& personID, const string& dutyID) {
	auto jvo = Uint64JsonVO::createShared();

	// ����һ��Service
	OrgJobService service;
	// ִ����������
	auto result = service.addData(personID, dutyID);
	if (result)
	{
		jvo->success(result);
	}
	else
	{
		jvo->fail(result);
	}
	//��Ӧ���
	return jvo;
}
