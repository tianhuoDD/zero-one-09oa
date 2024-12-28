/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 23:09:12

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
#include "modify_personal_identityService.h"
#include "dao/modify/modify_personal_identityDAO.h"
#include "../../domain/do/modify/org_identitypersonDO.h"

bool modify_personal_identityService::updateData(const modify_personal_identityDTO::Wrapper& dto)
{
	// 组装DO数据
	org_identitypersonDO data;
	data.setXid(dto->xid.getValue(" ")); 
	data.setXname(dto->xname.getValue(" "));
	data.setXmajor(dto->xmajor.getValue(""));
    // 执行数据修改
	modify_personal_identityDAO dao; 
	return dao.update(data) == 1;
}
