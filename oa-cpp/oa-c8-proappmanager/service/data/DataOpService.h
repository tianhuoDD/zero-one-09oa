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
#ifndef _DATAOP_SERVICE_
#define _DATAOP_SERVICE_
#include <list>
#include "../../oa-c8-proappmanager//domain/vo/data/DataOperatorVO.h"
#include "../../oa-c8-proappmanager/domain/dto/data/DataOperatorDTO.h"
#include "../../oa-c8-proappmanager/domain/do/data/DataOpDO.h"
#include "../../oa-c8-proappmanager/dao/data/DataOpratorDAO.h"
#include "SnowFlake.h"

class DataOpService
{
public:
	
	//新增数据
	string addData(const AddDataDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const DataOperatorDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const string& id);
	//将得到的ID号进行转换成16进制
	//string swtch(long long x);
};

#endif // !_DATAOP_SERVICE_

