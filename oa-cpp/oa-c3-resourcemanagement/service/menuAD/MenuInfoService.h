#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/24 15:13:11

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
#ifndef _MENUINFO_SERVICE_
#define _MENUINFO_SERVICE_
#include <list>
#include "domain/vo/menuinfo/MenuInfoVO.h"
#include "domain/query/menuinfo/MenuInfoQuery.h"
#include "domain/dto/menuinfo/MenuInfoDTO.h"

/**
 *  * 参考arch-demo写的，但是36行的数据格式可能有问题，同时MenuInfoService.h里的是分页查询的逻辑可能需要以后具体改
 */
class MenuInfoService
{
public:
	// 分页查询所有数据
	MenuInfoPageDTO::Wrapper listAll(const MenuInfoQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const MenuInfoDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const MenuInfoDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t menu_id);
	// 查询数据
	MenuInfoDTO::Wrapper queryData(const string& menu_id);
};

#endif // !_MENUINFO_SERVICE_

