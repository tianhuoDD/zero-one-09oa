#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/22 11:36:29

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
#ifndef _ORGUNITATTIBUTE_QUERY_
#define _ORGUNITATTIBUTE_QUERY_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class OrgUnitattributeQuery : public PageQuery
{
    DTO_INIT(OrgUnitattributeQuery, PageQuery);

    DTO_FIELD(List<String>, Xids);
    DTO_FIELD_INFO(Xids) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xids");
    }

    // org_unitattribute表下; 组织id; xid; varchar
    DTO_FIELD(String, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xid");
    }

    // org_unitattribute表下; 创建时间; xcreateTime; datetime
    DTO_FIELD(String, xcreateTime);
    DTO_FIELD_INFO(xcreateTime) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xcreateTime");
    }

    // org_unitattribute表下; 序列; xsequence; varchar
    DTO_FIELD(String, xsequence);
    DTO_FIELD_INFO(xsequence) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xsequence");
    }

    // org_unitattribute表下; 更新时间; xupdateTime; datetime
    DTO_FIELD(String, xupdateTime);
    DTO_FIELD_INFO(xupdateTime) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xupdateTime");
    }

    // org_unitattribute表下; 分配因子; xdistributeFactor; int
    DTO_FIELD(Int32, xdistributeFactor);
    DTO_FIELD_INFO(xdistributeFactor) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xdistributeFactor");
    }

    // org_unitattribute表下; 描述; xdescription; varchar
    DTO_FIELD(String, xdescription);
    DTO_FIELD_INFO(xdescription) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xdescription");
    }

    // org_unitattribute表下; 完整名; xdistinguishedName; varchar
    DTO_FIELD(String, xdistinguishedName);
    DTO_FIELD_INFO(xdistinguishedName) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xdistinguishedName");
    }

    // org_unitattribute表下; 名称; xname; varchar
    DTO_FIELD(String, xname);
    DTO_FIELD_INFO(xname) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xname");
    }

    // org_unitattribute表下; 排序号; xorderNumber; int
    DTO_FIELD(Int32, xorderNumber);
    DTO_FIELD_INFO(xorderNumber) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xorderNumber");
    }

    // org_unitattribute表下; 拼音; xpinyin; varchar
    DTO_FIELD(String, xpinyin);
    DTO_FIELD_INFO(xpinyin) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xpinyin");
    }

    // org_unitattribute表下; 拼音首字母; xpinyinInitial; varchar
    DTO_FIELD(String, xpinyinInitial);
    DTO_FIELD_INFO(xpinyinInitial) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xpinyinInitial");
    }

    // org_unitattribute表下; 唯一编码; xunique; varchar
    DTO_FIELD(String, xunique);
    DTO_FIELD_INFO(xunique) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xunique");
    }

    // org_unitattribute表下; 单位; xunit; varchar
    DTO_FIELD(String, xunit);
    DTO_FIELD_INFO(xunit) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.xunit");
    }
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_ORGUNITATTIBUTE_QUERY_