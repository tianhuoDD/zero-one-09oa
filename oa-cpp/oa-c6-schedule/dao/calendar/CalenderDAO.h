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
 * 示例表数据库操作实现
 */
class CalenderDAO : public BaseDAO
{
private:
	//新建日历数据插入的模板
	template<typename T>
	uint64_t executeInsert(const string& table, const string& filed, const T& Obj);
	//日历数据删除
	uint64_t executeDelete(const string& table, const string& xid);
	//日历数据查找和删除的组合
	uint64_t executeCDCombination(string xid);

public:
	//日历id查询
	uint64_t executeCount(const string& table, const string& xid, const string& xidType);

	uint64_t insert(const cal_calendarDO& iObj);
	// 插入管理者数据
	uint64_t insert(const cal_calendar_manageablepersonlistDO& iObj);
	// 插入可见范围的人数据
	uint64_t insert(const cal_calendar_viewablepersonlistDO& iObj);
	// 插入可见范围的组织数据
	uint64_t insert(const cal_calendar_viewableunitlistDO& iObj);
	// 插入可见范围的群组数据
	uint64_t insert(const cal_calendar_viewablegrouplistDO& iObj);
	// 插入可新建范围的人数据
	uint64_t insert(const cal_calendar_publishablepersonlistDO& iObj);
	// 插入可新建范围的组织数据
	uint64_t insert(const cal_calendar_publishableunitlistDO& iObj);
	// 插入可新建范围的群组数据
	uint64_t insert(const cal_calendar_publishablegrouplistDO& iObj);

	// 修改数据
	int update(const cal_calendarDO& uObj);

	// 通过ID删除数据
	int deleteById(string xid);
	// 重载删除函数，进行覆盖时的删除
	int deleteById(string xid, int i);
};
#endif // !_CALENDER_DAO_
