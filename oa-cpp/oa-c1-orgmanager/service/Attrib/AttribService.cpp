/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "AttribService.h"
#include "../../dao/Attrib/AttribDAO.h"
//query
AttribPageDTO::Wrapper AttribService::listAll(const AttribQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AttribPageDTO::createShared();
	pages->pageIndex = query->pageIndex;//1
	pages->pageSize = query->pageSize;//2

	// ��ѯ����������
	AttribDAO dao;
	uint64_t count = dao.count(query);//����
	if (count <= 0)//��ѯ��������
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;//3��������
	pages->calcPages();//4
	list<AttribDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (AttribDO sub : result)
	{
		auto dto = AttribDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();   
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, shuxing, Shuxing, value, Value, miaoshu, Miaoshu);//��DAO�����ݽ���cv
		pages->addData(dto);//5(��ʾ��ѯ���)
	}
	return pages;
}
//add
uint64_t AttribService::saveData(const AttribDTO::Wrapper& dto)
{
	// ��װDO����
	AttribDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
		//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, Shuxing, shuxing, Value, value, Miaoshu, miaoshu);
	// ִ���������
	AttribDAO dao;
	return dao.insert(data);
}
//modifiy
bool AttribService::updateData(const AttribDTO::Wrapper& dto)
{
	// ��װDO����
	AttribDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
		//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, Shuxing, shuxing, Value, value, Miaoshu, miaoshu);
	// ִ�������޸�
	AttribDAO dao;
	return dao.update(data) == 1;
}
//delete
bool AttribService::removeData(uint64_t id)
{
	AttribDAO dao;
	return dao.deleteById(id) == 1;
}
