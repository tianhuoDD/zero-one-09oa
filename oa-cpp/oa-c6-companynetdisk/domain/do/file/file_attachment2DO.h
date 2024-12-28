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
 * �ļ�����ʵ����
 */
class File_Attachment2DO
{
    // �ļ�id
    CC_SYNTHESIZE(std::string, attachmet2_xid, attachmet2_Xid);
    // �ļ�����ʱ��
    CC_SYNTHESIZE(std::string, attachmet2_xcreateTime, attachmet2_XcreateTime);
    // �ļ����к�
    CC_SYNTHESIZE(std::string, attachmet2_xsequence, attachmet2_Xsequence);
    // �ļ�����ʱ��
    CC_SYNTHESIZE(std::string, attachmet2_xupdateTime, attachmet2_XupdateTime);
    // �ļ��ַ���ʽ
    CC_SYNTHESIZE(int, attachmet2_xdistributeFactor, attachmet2_XdistributeFactor);
    // �ļ�����
    CC_SYNTHESIZE(std::string, attachmet2_xdescription, attachmet2_Xdescription);
    // �ļ���չ
    CC_SYNTHESIZE(std::string, attachmet2_xextension, attachmet2_Xextension);
    // �ļ��汾��
    CC_SYNTHESIZE(int, attachmet2_xfileVersion, attachmet2_XfileVersion);
    // �ļ�Ŀ¼
    CC_SYNTHESIZE(std::string, attachmet2_xfolder, attachmet2_Xfolder);
    // �ļ��ϴ��޸���
    CC_SYNTHESIZE(std::string, attachmet2_xlastUpdatePerson, attachmet2_XlastUpdatePerson);
    // �ļ��ϴ��޸�ʱ��
    CC_SYNTHESIZE(std::string, attachmet2_xlastUpdateTime, attachmet2_XlastUpdateTime);
    // �ļ�����
    CC_SYNTHESIZE(int64_t, attachmet2_xlength, attachmet2_Xlength);
    // �ļ�����
    CC_SYNTHESIZE(std::string, attachmet2_xname, attachmet2_Xname);
    // �ļ���ʼĿ¼
    CC_SYNTHESIZE(std::string, attachmet2_xoriginFile, attachmet2_XoriginFile);
    // �ļ�ӵ����
    CC_SYNTHESIZE(std::string, attachmet2_xperson, attachmet2_Xperson);
    // �ļ�״̬
    CC_SYNTHESIZE(std::string, attachmet2_xstatus, attachmet2_Xstatus);
    // �ļ�����
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