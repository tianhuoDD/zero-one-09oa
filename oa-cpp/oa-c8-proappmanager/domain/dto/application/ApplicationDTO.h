/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/19 23:10:24

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
#ifndef _APPLICATIONDTO_H_
#define _APPLICATIONDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ApplicationDTO : public oatpp::DTO
{
	DTO_INIT(ApplicationDTO, DTO);

	// 应用名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("application.field.name");
	}
	// 应用别名
	DTO_FIELD(String, xalias);
	DTO_FIELD_INFO(xalias) {
		info->description = ZH_WORDS_GETTER("application.field.alias");
	}
	// 应用类型
	DTO_FIELD(String, xapplicationCategory);
	DTO_FIELD_INFO(xapplicationCategory) {
		info->description = ZH_WORDS_GETTER("application.field.applicationCategory");
	}
	// ID
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("application.field.id");
	}

	DTO_FIELD(String, xcreateTime);
	DTO_FIELD_INFO(xcreateTime) {
		info->description = ZH_WORDS_GETTER("application.field.createTime");
	}
	DTO_FIELD(String, xsequence);
	DTO_FIELD_INFO(xsequence) {
		info->description = ZH_WORDS_GETTER("application.field.sequence");
	}
	DTO_FIELD(String, xupdateTime);
	DTO_FIELD_INFO(xupdateTime) {
		info->description = ZH_WORDS_GETTER("application.field.updateTime");
	}
	DTO_FIELD(Int32, xdistributeFactor);
	DTO_FIELD_INFO(xdistributeFactor) {
		info->description = ZH_WORDS_GETTER("application.field.distributeFactor");
	}
	DTO_FIELD(String, xcreatorPerson);
	DTO_FIELD_INFO(xcreatorPerson) {
		info->description = ZH_WORDS_GETTER("application.field.creatorPerson");
	}
	// 应用描述
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("application.field.description");
	}
	DTO_FIELD(String, xlastUpdatePerson);
	DTO_FIELD_INFO(xlastUpdatePerson) {
		info->description = ZH_WORDS_GETTER("application.field.lastUpdatePerson");
	}
	DTO_FIELD(String, xlastUpdateTime);
	DTO_FIELD_INFO(xlastUpdateTime) {
		info->description = ZH_WORDS_GETTER("application.field.lastUpdateTime");
	}
	DTO_FIELD(String, xproperties);
	DTO_FIELD_INFO(xproperties) {
		info->description = ZH_WORDS_GETTER("application.field.properties");
	}
	DTO_FIELD(String, xicon);
	DTO_FIELD_INFO(xicon) {
		info->description = ZH_WORDS_GETTER("application.field.icon");
	}
	DTO_FIELD(String, xiconHue);
	DTO_FIELD_INFO(xiconHue) {
		info->description = ZH_WORDS_GETTER("application.field.iconHue");
	}

	
};

class ApplicationPageDTO : public PageDTO<ApplicationDTO::Wrapper>
{
	DTO_INIT(ApplicationPageDTO, PageDTO<ApplicationDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONDTO_H_