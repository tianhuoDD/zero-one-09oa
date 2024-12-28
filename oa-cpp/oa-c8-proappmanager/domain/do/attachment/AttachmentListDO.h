#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _ATTACHMENTLIST_DO_
#define _ATTACHMENTLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class AttachmentListDO
{
	/** 定义受保护的变量，并提供get、set方法 */
	// 附件id
	CC_SYNTHESIZE(string, xid, Xid);
	// 附件名字
	CC_SYNTHESIZE(string, xname, Xname);
	// 
	CC_SYNTHESIZE(string, xalias, Xalias);
	//
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	//
	CC_SYNTHESIZE(string, xapplication, Xapplication);
	//
	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	//
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	//
	CC_SYNTHESIZE(string, xfileName, XfileName);
	//
	CC_SYNTHESIZE(int64_t,xlength, Xlength);
	// 
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// 
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);

public:
	AttachmentListDO() {
		xid = "0";
		xname = "";
		xalias = "";
		xdescription = "";
		xapplication = "";
		xlastUpdatePerson = "";
		xlastUpdateTime = "";
		xfileName = "";
		xlength = 0;
		xcreateTime = "";
		xupdateTime = "";
	}
};

#endif // !_SAMPLE_DO_
