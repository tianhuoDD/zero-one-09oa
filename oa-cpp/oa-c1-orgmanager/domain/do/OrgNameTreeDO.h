#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _ORGNAMETREEDO_H_
#define _ORGNAMETREEDO_H_

#include "DoInclude.h"
/**
 * 测试菜单数据库实体
 */
class OrgNameTreeDO
{
	//org_unit表下; 组织id; xid; varchar
	CC_SYNTHESIZE(string, xid, Xid);
	//org_unit表下; 组织名称; unit_xname; varchar
	CC_SYNTHESIZE(string, xname, Xname);
	//org_unit表下; 唯一编码; xunique; varchar
	CC_SYNTHESIZE(string, xunique, Xunique);
	//组织层级编号
	CC_SYNTHESIZE(int, xlevel, Xlevel);
	//组织层级名称
	CC_SYNTHESIZE(string, xlevelname, Xlevelname);
	//org_unit表下; 上级组织; xsuperior; varchar
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	//组织层级顺序编号
	CC_SYNTHESIZE(string, xlevelOrderNumber, XlevelOrderNumber);
public:
	OrgNameTreeDO() {}
	OrgNameTreeDO(string xid, string xname,string xunique, uint64_t xlevel, string xlevelname, string xsuperior, string xlevelOrderNumber)
	{
		this->xid = xid;
		this->xname = xname;
		this->xunique = xunique;
		this->xlevel = xlevel;
		this->xlevelname = xlevelname;
		this->xsuperior = xsuperior;
		this->xlevelOrderNumber = xlevelOrderNumber;
	}
};


#endif // !_ORGNAMETREEDO_H_