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
#ifndef _FILE_ATTACHMENT2_DO_
#define _FILE_ATTACHMENT2_DO_
#include "../../GlobalInclude.h"

/**
 * 文件附件实体类
 */
class File_Attachment2DO
{
    // 文件id
    CC_SYNTHESIZE(std::string, attachmet2_xid, attachmet2_Xid);
    // 文件创建时间
    CC_SYNTHESIZE(std::string, attachmet2_xcreateTime, attachmet2_XcreateTime);
    // 文件序列号
    CC_SYNTHESIZE(std::string, attachmet2_xsequence, attachmet2_Xsequence);
    // 文件更新时间
    CC_SYNTHESIZE(std::string, attachmet2_xupdateTime, attachmet2_XupdateTime);
    // 文件分发方式
    CC_SYNTHESIZE(int, attachmet2_xdistributeFactor, attachmet2_XdistributeFactor);
    // 文件描述
    CC_SYNTHESIZE(std::string, attachmet2_xdescription, attachmet2_Xdescription);
    // 文件扩展
    CC_SYNTHESIZE(std::string, attachmet2_xextension, attachmet2_Xextension);
    // 文件版本号
    CC_SYNTHESIZE(int, attachmet2_xfileVersion, attachmet2_XfileVersion);
    // 文件目录
    CC_SYNTHESIZE(std::string, attachmet2_xfolder, attachmet2_Xfolder);
    // 文件上次修改人
    CC_SYNTHESIZE(std::string, attachmet2_xlastUpdatePerson, attachmet2_XlastUpdatePerson);
    // 文件上次修改时间
    CC_SYNTHESIZE(std::string, attachmet2_xlastUpdateTime, attachmet2_XlastUpdateTime);
    // 文件长度
    CC_SYNTHESIZE(int64_t, attachmet2_xlength, attachmet2_Xlength);
    // 文件名称
    CC_SYNTHESIZE(std::string, attachmet2_xname, attachmet2_Xname);
    // 文件初始目录
    CC_SYNTHESIZE(std::string, attachmet2_xoriginFile, attachmet2_XoriginFile);
    // 文件拥有者
    CC_SYNTHESIZE(std::string, attachmet2_xperson, attachmet2_Xperson);
    // 文件状态
    CC_SYNTHESIZE(std::string, attachmet2_xstatus, attachmet2_Xstatus);
    // 文件类型
    CC_SYNTHESIZE(std::string, attachmet2_xtype, attachmet2_Xtype);

public:
    File_Attachment2DO()
    {
        attachmet2_xid = "";
        attachmet2_xcreateTime = "";
        attachmet2_xsequence = "";
        attachmet2_xupdateTime = "";
        attachmet2_xdistributeFactor = 0;
        attachmet2_xdescription = "";
        attachmet2_xextension = "";
        attachmet2_xfileVersion = 0;
        attachmet2_xfolder = "";
        attachmet2_xlastUpdatePerson = "";
        attachmet2_xlastUpdateTime = "";
        attachmet2_xlength = 0;
        attachmet2_xname = "";
        attachmet2_xoriginFile = "";
        attachmet2_xperson = "";
        attachmet2_xstatus = "";
        attachmet2_xtype = "";
    }
};

#endif // !_FILE_ATTACHMENT2_DO_