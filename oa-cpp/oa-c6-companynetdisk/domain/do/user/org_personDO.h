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
#ifndef _ORG_PERSONDO_H_
#define _ORG_PERSONDO_H_
#include "../../GlobalInclude.h"
#include "../DoInclude.h"
class org_personDO {
    //�û�Ψһ��ʶid
    CC_SYNTHESIZE(string, xid, Xid);
    CC_SYNTHESIZE(string, xunique, Xunique);
    // �û�����
    CC_SYNTHESIZE(string, xname, Xname);
    // �û����к�
    CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
public:
    org_personDO() {}
    // ����
    org_personDO(string xid, string xname, string xdistinguishName)
    {
        this->xid = xid;
        this->xname = xname;
        this->xdistinguishedName = xdistinguishedName;
    }
};

#endif // !_ORG_PERSONDO_H_