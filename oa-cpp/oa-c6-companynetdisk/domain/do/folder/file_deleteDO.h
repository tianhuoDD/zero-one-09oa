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
#ifndef _FILE_DELETEDO_H_
#define _FILE_DELETEDO_H_
#include "../../GlobalInclude.h"
#include "SimpleDateTimeFormat.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class file_deleteDO
{
	// �ļ����
	CC_SYNTHESIZE(string, xid, Xid);
	// Ŀ¼����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// Ŀ¼���к�
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// Ŀ¼����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// Ŀ¼�ַ�����
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// Ŀ¼��
	CC_SYNTHESIZE(string, xname, Xname);
	// ��Ŀ¼id
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	// �ļ��ϴθ���ʱ��
	//CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
public:
	file_deleteDO() {
		xid = "123456";
		xcreateTime = "2024-10-23 21:24";
		xsequence = "654321";
		xupdateTime = SimpleDateTimeFormat::format();
		xdistributeFactor = 66666;
		xname = "c6";
		xsuperior = "123456789";
		//xlastUpdateTime = SimpleDateTimeFormat::format();
	}
};

#endif // !_FILE_FOLDERDO_H_
