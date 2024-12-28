#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/20 23:09:08

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
#ifndef _ORGUNITATTRIBUTE_DTO_H_
#define _ORGUNITATTRIBUTE_DTO_H_

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个修改用户信息的数据传输模型
 */
class OrgUnitattributeDTO : public oatpp::DTO
{
    DTO_INIT(OrgUnitattributeDTO, DTO);

    // org_unitattribute表下; 组织id; xid; varchar
    DTO_FIELD(String, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xid");
    }

    // org_unitattribute表下; 创建时间; xcreateTime; datetime
    DTO_FIELD(String, xcreateTime);
    DTO_FIELD_INFO(xcreateTime) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xcreateTime");
    }

    // org_unitattribute表下; 序列; xsequence; varchar
    DTO_FIELD(String, xsequence);
    DTO_FIELD_INFO(xsequence) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xsequence");
    }

    // org_unitattribute表下; 更新时间; xupdateTime; datetime
    DTO_FIELD(String, xupdateTime);
    DTO_FIELD_INFO(xupdateTime) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xupdateTime");
    }

    // org_unitattribute表下; 分配因子; xdistributeFactor; int
    DTO_FIELD(Int32, xdistributeFactor);
    DTO_FIELD_INFO(xdistributeFactor) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xdistributeFactor");
    }

    // org_unitattribute表下; 描述; xdescription; varchar
    DTO_FIELD(String, xdescription);
    DTO_FIELD_INFO(xdescription) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xdescription");
    }

    // org_unitattribute表下; 完整名; xdistinguishedName; varchar
    DTO_FIELD(String, xdistinguishedName);
    DTO_FIELD_INFO(xdistinguishedName) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xdistinguishedName");
    }

    // org_unitattribute表下; 名称; xname; varchar
    DTO_FIELD(String, xname);
    DTO_FIELD_INFO(xname) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xname");
    }

    // org_unitattribute表下; 排序号; xorderNumber; int
    DTO_FIELD(Int32, xorderNumber);
    DTO_FIELD_INFO(xorderNumber) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xorderNumber");
    }

    // org_unitattribute表下; 拼音; xpinyin; varchar
    DTO_FIELD(String, xpinyin);
    DTO_FIELD_INFO(xpinyin) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xpinyin");
    }

    // org_unitattribute表下; 拼音首字母; xpinyinInitial; varchar
    DTO_FIELD(String, xpinyinInitial);
    DTO_FIELD_INFO(xpinyinInitial) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xpinyinInitial");
    }

    // org_unitattribute表下; 唯一编码; xunique; varchar
    DTO_FIELD(String, xunique);
    DTO_FIELD_INFO(xunique) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xunique");
    }

    // org_unitattribute表下; 单位; xunit; varchar
    DTO_FIELD(String, xunit);
    DTO_FIELD_INFO(xunit) {
        info->description = ZH_WORDS_GETTER("org.unitattribute.field.xunit");
    }
};


/**
 * 定义一个用户信息分页传输对象
 */
class OrgUnitattributePageDTO : public PageDTO<OrgUnitattributeDTO::Wrapper>
{
	DTO_INIT(OrgUnitattributePageDTO, PageDTO<OrgUnitattributeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _ORGUNITATTRIBUTE_DTO_H_