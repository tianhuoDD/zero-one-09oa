#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _CALENDER_DAO_
#define _CALENDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewableunitlistDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CalenderDAO : public BaseDAO
{
private:
	//�½��������ݲ����ģ��
	template<typename T>
	uint64_t executeInsert(const string& table, const string& filed, const T& Obj);
	//��������ɾ��
	uint64_t executeDelete(const string& table, const string& xid);
	//�������ݲ��Һ�ɾ�������
	uint64_t executeCDCombination(string xid);

public:
	//����id��ѯ
	uint64_t executeCount(const string& table, const string& xid, const string& xidType);

	uint64_t insert(const cal_calendarDO& iObj);
	// �������������
	uint64_t insert(const cal_calendar_manageablepersonlistDO& iObj);
	// ����ɼ���Χ��������
	uint64_t insert(const cal_calendar_viewablepersonlistDO& iObj);
	// ����ɼ���Χ����֯����
	uint64_t insert(const cal_calendar_viewableunitlistDO& iObj);
	// ����ɼ���Χ��Ⱥ������
	uint64_t insert(const cal_calendar_viewablegrouplistDO& iObj);
	// ������½���Χ��������
	uint64_t insert(const cal_calendar_publishablepersonlistDO& iObj);
	// ������½���Χ����֯����
	uint64_t insert(const cal_calendar_publishableunitlistDO& iObj);
	// ������½���Χ��Ⱥ������
	uint64_t insert(const cal_calendar_publishablegrouplistDO& iObj);

	// �޸�����
	int update(const cal_calendarDO& uObj);

	// ͨ��IDɾ������
	int deleteById(string xid);
	// ����ɾ�����������и���ʱ��ɾ��
	int deleteById(string xid, int i);
};
#endif // !_CALENDER_DAO_
