#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
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
#ifndef _ORGANIZATION_DO_
#define _ORGANIZATION_DO_
#include "../DoInclude.h" //包含其他依赖项，不用去看

/**
 * 示例组织名称实体类
 */
class OrganizationNameDO
{
	// 姓名
	CC_SYNTHESIZE(string, xname, Name);
	// ID
	CC_SYNTHESIZE(string, xid, Id);
	//CC_SYNTHESIZE(string, xmajor, Major);
public:
	OrganizationNameDO() {
		xname= "01_Shanghai";
		xid= "123456";
		//xmajor = "01_Total";
	}
};

/**
 * 示例组织成员实体类
 */
class OrganizationMemberDO
{
	// 姓名
	CC_SYNTHESIZE(string, xname, Name);
	// ID
	CC_SYNTHESIZE(string, xid, Id);
	// 所属公司
	CC_SYNTHESIZE(string, xemployee, XEmployee);

public:
	OrganizationMemberDO() {
		xname= "Rif(Member)";
		xid= "123456";
		xemployee = "01 Star";
	}

	/*void setEmployee(std::string xEmployee);
	std::string getEmployee();*/
};

//inline void OrganizationMemberDO::setEmployee(std::string xEmployee)
////.h中非要实现函数，必须使用inline。否则会遇到redefine的问题
//{
//	xemployee = xEmployee;
//}
//
//inline std::string OrganizationMemberDO::getEmployee()
//{
//	return this->xemployee;
//}

#endif // !_ORGANIZATION_DO_
