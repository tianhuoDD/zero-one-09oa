#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _DATAOPERATOR_DTO_
#define _DATAOPERATOR_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class DataOperatorDTO : public oatpp::DTO
{
	DTO_INIT(DataOperatorDTO, DTO);
	//流程数据id
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"), true, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"));

	//数据配置列id
	//API_DTO_FIELD(String, itemid, ZH_WORDS_GETTER("dataconfiguration.item.item-id"), false, " ");

	//流程数据配置名字(显示)
	API_DTO_FIELD(String,name,ZH_WORDS_GETTER("dataconfiguration.datamessage.name"),true,ZH_WORDS_GETTER("dataconfiguration.datamessage.name"));

	//流程数据配置别名(显示)
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("dataconfiguration.datamessage.alias"),true,ZH_WORDS_GETTER("dataconfiguration.datamessage.alias"));

	//流程数据配置序列号
	API_DTO_FIELD_DEFAULT(String, sequence,ZH_WORDS_GETTER("dataconfiguration.datamessage.sequence"));

	//流程数据配置描述
	API_DTO_FIELD(String, description, ZH_WORDS_GETTER("dataconfiguration.datamessage.description"), false, "");

	//流程数据配置所属应用号
	API_DTO_FIELD(String, application, ZH_WORDS_GETTER("dataconfiguration.datamessage.application"), true, "");
	
	//数据配置分配因子
	API_DTO_FIELD_DEFAULT(UInt64, distributefactor, ZH_WORDS_GETTER("dataconfiguration.datamessage.distributefactor"));

	//文本类型 
	API_DTO_FIELD_DEFAULT(String, text, ZH_WORDS_GETTER("dataconfiguration.item.text"));

	//主表列bool类型值
	API_DTO_FIELD_DEFAULT(Boolean, booleanvalue, ZH_WORDS_GETTER("dataconfiguration.item.boolean-value"));

	//主表列列的时间列值
	API_DTO_FIELD(String, datetimevalue, ZH_WORDS_GETTER("dataconfiguration.item.date-time-value"), false, "2000/1/1 00:00");

	//主表列列的日期值
	API_DTO_FIELD(String, datevalue, ZH_WORDS_GETTER("dataconfiguration.item.date-value"), false,"2000/1/1");

	//主表列列原始类型
	API_DTO_FIELD(String, itemprimitivetype, ZH_WORDS_GETTER("dataconfiguration.item.item-primitive-type"), false, "o");

	//主表字符串列表
	API_DTO_FIELD(String, itemstringvaluetype, ZH_WORDS_GETTER("dataconfiguration.item.item-string-value-type"), false, "s");

	//object类型检测
	API_DTO_FIELD(String, itemtype, ZH_WORDS_GETTER("dataconfiguration.item.item-type"), false, "o");

	// number-value: number表单类型值 
	API_DTO_FIELD_DEFAULT(UInt64, numbervalue, ZH_WORDS_GETTER("dataconfiguration.item.number-value"));

	//   time-value: 列时间类型值
	API_DTO_FIELD(String, timevalue, ZH_WORDS_GETTER("dataconfiguration.item.time-value"), false, "00:00");

	//项目分类
	API_DTO_FIELD(String,category, ZH_WORDS_GETTER("dataconfiguration.item.item-category"), false, " ");


	//新增表单列名字
	//最多增加七个表单，默认存放位置为-1
	API_DTO_FIELD_DEFAULT(String, data,ZH_WORDS_GETTER("dataconfiguration.item.data"));


};

class IdDataDTO : public oatpp::DTO
{
	DTO_INIT(IdDataDTO, DTO);
	//流程数据id
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"), true, "0");

	//数据配置列id
	//API_DTO_FIELD(String, itemid, ZH_WORDS_GETTER("dataconfiguration.item.item-id"), false, "0");

};

class AddDataDTO : public oatpp::DTO 
{
	DTO_INIT(AddDataDTO, DTO);

	//流程数据配置名字(显示)
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("dataconfiguration.datamessage.name"), true, "name");

	//流程数据配置别名(显示)
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("dataconfiguration.datamessage.alias"), true,"alias");

	//流程数据配置序列号
	API_DTO_FIELD_DEFAULT(String, sequence, ZH_WORDS_GETTER("dataconfiguration.datamessage.sequence"));

	//流程数据配置描述
	API_DTO_FIELD(String, description, ZH_WORDS_GETTER("dataconfiguration.datamessage.description"), false, "");

	//流程数据配置所属应用号
	API_DTO_FIELD(String, application, ZH_WORDS_GETTER("dataconfiguration.datamessage.application"), true, " ");

	//数据配置分配因子
	API_DTO_FIELD_DEFAULT(UInt64, distributefactor, ZH_WORDS_GETTER("dataconfiguration.datamessage.distributefactor"));

	//文本类型 
	API_DTO_FIELD_DEFAULT(String, text, ZH_WORDS_GETTER("dataconfiguration.item.text"));

	//主表列bool类型值
	API_DTO_FIELD_DEFAULT(Boolean, booleanvalue, ZH_WORDS_GETTER("dataconfiguration.item.boolean-value"));

	//主表列列的时间列值
	API_DTO_FIELD(String, datetimevalue, ZH_WORDS_GETTER("dataconfiguration.item.date-time-value"), false, "2000/1/1 00:00");

	//主表列列的日期值
	API_DTO_FIELD(String, datevalue, ZH_WORDS_GETTER("dataconfiguration.item.date-value"), false, "2000/1/1");

	//主表列列原始类型
	API_DTO_FIELD(String, itemprimitivetype, ZH_WORDS_GETTER("dataconfiguration.item.item-primitive-type"), false, "o");

	//主表字符串列表
	API_DTO_FIELD(String, itemstringvaluetype, ZH_WORDS_GETTER("dataconfiguration.item.item-string-value-type"), false, "s");

	//object类型检测
	API_DTO_FIELD(String, itemtype, ZH_WORDS_GETTER("dataconfiguration.item.item-type"), false, "o");

	// number-value: number表单类型值 
	API_DTO_FIELD_DEFAULT(UInt64, numbervalue, ZH_WORDS_GETTER("dataconfiguration.item.number-value"));

	//   time-value: 列时间类型值
	API_DTO_FIELD(String, timevalue, ZH_WORDS_GETTER("dataconfiguration.item.time-value"), false, "00:00");

	//项目分类
	API_DTO_FIELD(String, category, ZH_WORDS_GETTER("dataconfiguration.item.item-category"), false, " ");


	//新增表单列名字
	//最多增加七个表单，默认存放位置为-1
	API_DTO_FIELD_DEFAULT(String, data, ZH_WORDS_GETTER("dataconfiguration.item.data"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DATAOPERATOR_DTO_