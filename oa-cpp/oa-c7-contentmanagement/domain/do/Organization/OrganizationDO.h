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
#include "../DoInclude.h" //�����������������ȥ��

/**
 * ʾ����֯����ʵ����
 */
class OrganizationNameDO
{
	// ����
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
 * ʾ����֯��Աʵ����
 */
class OrganizationMemberDO
{
	// ����
	CC_SYNTHESIZE(string, xname, Name);
	// ID
	CC_SYNTHESIZE(string, xid, Id);
	// ������˾
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
////.h�з�Ҫʵ�ֺ���������ʹ��inline�����������redefine������
//{
//	xemployee = xEmployee;
//}
//
//inline std::string OrganizationMemberDO::getEmployee()
//{
//	return this->xemployee;
//}

#endif // !_ORGANIZATION_DO_
