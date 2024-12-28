#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _DATA_CONFIG_SERVICE_
#define _DATA_CONFIG_SERVICE_
#include <list>
#include "domain/vo/data-config/DataConfigVO.h"
#include "domain/dto/data-config/DataConfigDTO.h"

/**
 * 数据配置服务实现
 */
class DataConfigService
{
public:
	// 查询字典id的所有数据
	DataConfigVO::Wrapper queryByXid(const string& xid);
	// 保存数据
	string saveData(const AddDataConfigDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ModifyDataConfigDTO::Wrapper& dto);
	//// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_DATA_CONFIG_SERVICE_
