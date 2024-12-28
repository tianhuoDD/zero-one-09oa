#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:51:41

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
#ifndef _DATAOP_DO_
#define _DATAOP_DO_

#include "Macros.h"
#include <string>
#include <list>
using namespace std;

class DataOpDO
{
	// 流程数据配置ID
	CC_SYNTHESIZE(string, id, Id);

	//	item - id : 表单列ID号
	CC_SYNTHESIZE(string, itemid, ItemId);
	
	//流程数据配置名字
	CC_SYNTHESIZE(string, name, Name);
	
	//流程数据配置别名
	CC_SYNTHESIZE(string, alias, Alias);
	
	//流程数据配置描述
	CC_SYNTHESIZE(string, description, Description);

	//流程数据配置创建时间（时间类型date）
	CC_SYNTHESIZE(string, createtime, CreateTime);

	//流程数据配置更新时间
	CC_SYNTHESIZE(string, updatetime, UpdateTime);

	//流程数据所属应用号
	CC_SYNTHESIZE(string, application, Application);

	//流程数据配置序列号
	CC_SYNTHESIZE(string, sequence, Sequence);

	//数据配置分配因子
	CC_SYNTHESIZE(uint64_t, distributefactor, DistributeFactor);

	//		bundle : 捆绑流程数据配置ID号
	CC_SYNTHESIZE(string, bundle, Bundle);

	//		item - type : object类型检测 如果是object则为o 否为p
	CC_SYNTHESIZE(string, itemtype, ItemType);

	//		item - primitive - type : 表单行原始数据类型 已首字母小写来表示该表单列的值的类型
	CC_SYNTHESIZE(string, itemprimitivetype, ItemPrimitiveType);

	//		item - string - value - type : 表单是否为字符类型数据 s为是string u为其他数据类型
	CC_SYNTHESIZE(string, itemstringvaluetype, ItemStringValueType);

	//		item - category : 项目分类 此表单列属于哪个项目中
	CC_SYNTHESIZE(string, itemcategory, ItemCategory);

	//		number - value : number表单类型值
	CC_SYNTHESIZE(double_t, numbervalue, NumberValue);

	//		boolean - value : 表单布尔类型值
	CC_SYNTHESIZE(bool, boolvalue, BoolValue);

	//		date - time - value : 表单时间类型值(带时间)
	CC_SYNTHESIZE(string, datetimevalue, DateTimeValue);

	//		date - value : 表单时间类型值(日期)
	CC_SYNTHESIZE(string, datevalue, DateValue);

	//文本值类型
	CC_SYNTHESIZE(string, text, Text);

	//   time-value: 列时间类型值
	CC_SYNTHESIZE(string,timevalue,TimeValue);

	//数据字段 列名和数据都先存放在这里然后进行分层和分析
	CC_SYNTHESIZE(string, data, Data);




	public:
	DataOpDO() {
		id = " ";
		itemid = " ";
		name = " ";
		alias = " ";
		description = " ";
		createtime = " ";
		updatetime = " ";
		application = " ";
		sequence = " ";
		distributefactor = 0;
		bundle = " ";
		itemtype = "o";
		itemprimitivetype = "o";
		itemstringvaluetype = "o";
		itemcategory = "pp_dict";
		numbervalue = 0.0;
		boolvalue = false;
		datetimevalue = "2000/1/1 00:00";
		datevalue = "2000/1/1";
		data = " ";
	}
};


class DataOpItemDO
{

	//	item - id : 表单列ID号
	CC_SYNTHESIZE(string, itemid, ItemId);


	// 流程数据配置ID
	CC_SYNTHESIZE(string, id, Id);


	public:
		DataOpItemDO() {
			id = " ";
			itemid = " ";
		}

};


#endif // !_DO_INCLUDE_
