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
#include "formTemplateBuiltService.h"
#include"../../../dao/FormTemplate/built/formTemplateBuiltDAO.h"


uint64_t formTemplateBuiltService::saveData(const formTemplateBuiltDTO::Wrapper& dto)
{
	// 组装DO数据
	formTemplateBuiltDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Sequence, xsequence,DistributeFactor, xdistributeFactor, Alias, xalias, Category, xcategory, Data, xdata, Description, xdescription, Icon, xicon, MobileData, xmobileData, Name, xname, Outline, xoutline)
		// 执行数据添加
		formTemplateBuiltDAO dao;
	return dao.insert(data);
}



bool formTemplateBuiltService::removeData(uint64_t id)
{
	formTemplateBuiltDAO dao;
	return dao.deleteById(id) == 1;
}
