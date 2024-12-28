#pragma 
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/22 17:06:21

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
#ifndef _ORGNAMETREEDTO_H_
#define _ORGNAMETREEDTO_H_

#include "../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class OrgNameTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(OrgNameTreeDTO, DTO);
	// 组织id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("organization.field.xid"));
	// 组织名称
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("organization.field.xname"));
	//组织编码
	API_DTO_FIELD_DEFAULT(String, xunique, ZH_WORDS_GETTER("organization.field.xunique"));
	// 组织层级
	API_DTO_FIELD_DEFAULT(Int32, xlevel, ZH_WORDS_GETTER("organization.field.xlevel"));
	//API_DTO_FIELD(Int32, level, ZH_WORDS_GETTER("organization.field.xunique"), false, 0);
	// 组织层级名称
	API_DTO_FIELD_DEFAULT(String, xlevelname, ZH_WORDS_GETTER("organization.field.xlevelname"));
	//同层级排序值
	API_DTO_FIELD_DEFAULT(String, xlevelOrderNumber, ZH_WORDS_GETTER("organization.field.xlevelOrderNumber"));

	// 子菜单
	API_DTO_FIELD(List<OrgNameTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("organization.field.orgsub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<OrgNameTreeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGNAMETREEDTO_H_