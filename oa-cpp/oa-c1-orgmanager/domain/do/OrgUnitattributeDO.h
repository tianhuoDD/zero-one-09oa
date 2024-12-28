#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/22 13:52:32

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
#ifndef _ORGUNITATTIBUTE_DO_
#define _ORGUNITATTIBUTE_DO_
#include "DoInclude.h"

/**
 * 示例数据库实体类
 */
class OrgUnitattributeDO
{
    // org_unitattribute表下; 组织id; xid; varchar
    CC_SYNTHESIZE(string, xid, Xid);
    // org_unitattribute表下; 创建时间; xcreateTime; datetime
    CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
    // org_unitattribute表下; 序列; xsequence; varchar
    CC_SYNTHESIZE(string, xsequence, Xsequence);
    // org_unitattribute表下; 更新时间; xupdateTime; datetime
    CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
    // org_unitattribute表下; 分配因子; xdistributeFactor; int
    CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
    // org_unitattribute表下; 描述; xdescription; varchar
    CC_SYNTHESIZE(string, xdescription, Xdescription);
    // org_unitattribute表下; 完整名; xdistinguishedName; varchar
    CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
    // org_unitattribute表下; 名称; xname; varchar
    CC_SYNTHESIZE(string, xname, Xname);
    // org_unitattribute表下; 排序号; xorderNumber; int
    CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
    // org_unitattribute表下; 拼音; xpinyin; varchar
    CC_SYNTHESIZE(string, xpinyin, Xpinyin);
    // org_unitattribute表下; 拼音首字母; xpinyinInitial; varchar
    CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
    // org_unitattribute表下; 唯一编码; xunique; varchar
    CC_SYNTHESIZE(string, xunique, Xunique);
    // org_unitattribute表下; 单位; xunit; varchar
    CC_SYNTHESIZE(string, xunit, Xunit);

public:
	OrgUnitattributeDO() {
        xid = "";
        xcreateTime = "";
        xsequence = "";
        xupdateTime = "";
        xdistributeFactor = 0;
        xdescription = "";
        xdistinguishedName = "";
        xname = "";
        xorderNumber = -1;
        xpinyin = "";
        xpinyinInitial = "";
        xunique = "";
        xunit = "";
	}
};

#endif // !_ORGUNITATTIBUTE_DO_
