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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/remove/CdeleteVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/CdeleteDTO.h"
//#include "../../service/contents/contentsservice.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ContentsService
{
public:
	// 重命名目录和文件
	bool updateContents(const CdeleteDTO::Wrapper& dto);
	// 通过ID删除目录
	bool removeContents(string xid);
};

#endif // !_SAMPLE_SERVICE_

