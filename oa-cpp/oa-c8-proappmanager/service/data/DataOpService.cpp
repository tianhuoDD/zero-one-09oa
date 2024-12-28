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
#include "DataOpService.h"


static string getCurrTimeWithMillis() {
	auto now = std::chrono::system_clock::now();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* ltm = localtime(&now_c);
	char timeStr[24];
	strftime(timeStr, sizeof(timeStr), "%Y%m%d%H%M%S", ltm);
	snprintf(timeStr + 14, sizeof(timeStr) - 14, "%03d", static_cast<int>(millis.count()));
	return string(timeStr);
}

static string getCurrTime() {
	// 获取当前时间:2021-01-01 12:00:00
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", ltm);
	return string(timeStr);
}



string DataOpService::addData(const AddDataDTO::Wrapper& dto) {
	DataOpDO data;
	SnowFlake s1(8, 3);
	auto xid = s1.nextId();
	auto xitemid = s1.nextId();
	string id_value = to_string(xid);
	string itemid_value = to_string(xitemid);
	data.setId(id_value);
	data.setItemId(itemid_value);
	data.setName(dto->name);
	data.setAlias(dto->alias);
	data.setDescription(dto->description);
	data.setApplication(dto->application);
	string serialNumber = getCurrTimeWithMillis() + id_value;
	data.setSequence(serialNumber);
	data.setData(dto->data);
	data.setBoolValue(dto->booleanvalue);
	data.setDateTimeValue(dto->datetimevalue);
	data.setDateValue(dto->datevalue);
	data.setItemPrimitiveType(dto->itemprimitivetype);
	data.setItemStringValueType(dto->itemstringvaluetype);
	data.setItemType(dto->itemtype);
	data.setNumberValue(dto->numbervalue);
	data.setTimeValue(dto->timevalue);
	data.setItemCategory(dto->category);
	DataOpDAO dao;
	if (dao.insert(data) == 1) {
		return id_value;
	} else return "";
}


bool DataOpService::updateData(const DataOperatorDTO::Wrapper& dto) {
	// 组装DO数据
	DataOpDO data;
	data.setId(dto->id);
	data.setName(dto->name);
	data.setAlias(dto->alias);
	data.setDescription(dto->description);
	data.setBoolValue(dto->booleanvalue);
	data.setDateTimeValue(dto->datetimevalue);
	data.setDateValue(dto->datevalue);
	data.setItemPrimitiveType(dto->itemprimitivetype);
	data.setItemStringValueType(dto->itemstringvaluetype);
	data.setItemType(dto->itemtype);
	data.setNumberValue(dto->numbervalue);
	data.setTimeValue(dto->timevalue);
	data.setData(dto->data);
	DataOpDAO dao;
	int res = dao.update(data);
	return res == 1 || res == 2;
}

bool DataOpService::removeData(const string& id) {
	DataOpDAO dao;

	return dao.deleteById(id) == 1;
}


//string  DataOpService:: swtch(long long x) {
//	srand(time(0));
//	unsigned long long random_number = ((unsigned long long)rand() << 32) | rand() << 16 | rand();
//	cout << random_number << endl;
//	uint32_t time_low = static_cast<uint32_t>(x & 0xFFFFFFFF);
//	uint32_t time_mid = static_cast<uint32_t>((x >> 32) & 0xFFFF);
//	uint32_t time_hi_and_version = static_cast<uint32_t>((x >> 48) & 0x0FFF);
//	uint32_t clock_seq = rand();  // 固定的版本号
//	uint64_t node = random_number;  // 可以用其它方法生成
//
//	// 使用字符串流格式化为 UUID 字符串
//	std::ostringstream oss;
//	oss << std::hex << std::setfill('0')
//		<< std::setw(8) << time_low << '-'
//		<< std::setw(4) << time_mid << '-'
//		<< std::setw(4) << (time_hi_and_version | 0x4000) << '-' // 设置版本为 4
//		<< std::setw(4) << clock_seq << '-'
//		<< std::setw(12) << node;
//		return oss.str();
//}