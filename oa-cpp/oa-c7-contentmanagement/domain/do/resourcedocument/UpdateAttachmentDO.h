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
#ifndef _UPDATEATTACHMENTDO_H_
#define _UPDATEATTACHMENTDO_H_

#include "../DoInclude.h"
/**
 * 测试菜单数据库实体
 */
class UpdateAttachmentDO
{
	CC_SYNTHESIZE(string, id, xId);
	CC_SYNTHESIZE(string, xappid, xAppId);
	CC_SYNTHESIZE(string, xdescription, xDescription);
	CC_SYNTHESIZE(string, xname, xName);
	CC_SYNTHESIZE(string, xupdatetime, xUpdateTime);
	CC_SYNTHESIZE(string, xalias, xAlias);
	CC_SYNTHESIZE(string, xfilename, xFileName);
public:
	UpdateAttachmentDO()
	{
		this->id = "";
		this->xappid = "";
		this->xdescription = "";
		this->xname = "";
		this->xupdatetime = "";
		this->xalias = "";
		this->xfilename = "";
	}
	UpdateAttachmentDO(string id, string xappid, string xdescription, string xname, string xupdatetime,string xalias,string xfilename)
	{
		this->id = id;
		this->xappid = xappid;
		this->xdescription = xdescription;
		this->xname = xname;
		this->xupdatetime = xupdatetime;
		this->xalias = xalias;
		this->xfilename = xfilename;
	}
};

#endif // !_UPDATEATTACHMENTDO_H_