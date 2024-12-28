#pragma once
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
#ifndef _NEW_DO_
#define _NEW_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class NewDO
{
	// 编号
protected: string icon; public: string getxappIcon(void) const {
	return icon;
}public: void setxappIcon(string var) {
	icon = var;
};
	// 姓名
	   CC_SYNTHESIZE(int, id, id);
	CC_SYNTHESIZE(string, name, xappName);
	// 性别
	CC_SYNTHESIZE(string, alias, xappAlias);
	// 年龄
	CC_SYNTHESIZE(string, description, xdescription);
	CC_SYNTHESIZE(string, sequence, xsequence);
	CC_SYNTHESIZE(string, documentType, xdocumentType);
	CC_SYNTHESIZE(string, ignore1, ignore1);
	CC_SYNTHESIZE(string, timed, timed);
	CC_SYNTHESIZE(string, appType, xappType);
	CC_SYNTHESIZE(string, showAlldocuments, xshowAlldocuments);
	CC_SYNTHESIZE(string, autosave, autosave);
	CC_SYNTHESIZE(string, defaultEditForm, xdefaultEditForm);
	CC_SYNTHESIZE(string, defaultReadForm, xdefaultReadForm);
	

public:
	NewDO() {
		icon = "";
		name = "";
		alias = "";
		description = "";
		sequence = "";
		documentType = "";
		ignore1 = "";
		timed = "";
		appType = "";
		showAlldocuments = "";
		autosave = "";
		defaultEditForm = "";
		defaultReadForm = "";
	}
};

#endif // !_SAMPLE_DO_
