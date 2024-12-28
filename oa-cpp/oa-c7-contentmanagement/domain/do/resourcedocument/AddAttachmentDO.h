#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2023/02/17 16:25:30

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
#ifndef _ADDATTACHMENTDO_H_
#define _ADDATTACHMENTDO_H_

#include "../DoInclude.h"
/**
 * 测试菜单数据库实体
 */
class AddAttachmentDO
{
	CC_SYNTHESIZE(string, id, xId);
	CC_SYNTHESIZE(string, xappid, xAppId);
	CC_SYNTHESIZE(string, xdescription, xDescription);
	CC_SYNTHESIZE(string, xname, xName);
	CC_SYNTHESIZE(string, xupdatetime, xUpdateTime);
public:
	AddAttachmentDO() 
	{
		this->id = "";
		this->xappid = "";
		this->xdescription = "";
		this->xname = "";
		this->xupdatetime = "";
	}
	AddAttachmentDO(string id, string xappid, string xdescription, string xname, string xupdatetime)
	{
		this->id = id;
		this->xappid = xappid;
		this->xdescription = xdescription;
		this->xname = xname;
		this->xupdatetime = xupdatetime;
	}
};

#endif // !_ADDATTACHMENTDO_H_