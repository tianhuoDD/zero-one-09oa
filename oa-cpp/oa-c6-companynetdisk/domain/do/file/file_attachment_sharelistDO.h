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
#ifndef _FILE_ATTACHMENT_SHARELIST_DO_
#define _FILE_ATTACHMENT_SHARELIST_DO_
#include "../../GlobalInclude.h"
#include "../user/org_personDO.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class file_attachment_sharelistDO : public org_personDO
{
	//�ļ�id
	CC_SYNTHESIZE(string, ATTACHMENT_XID, attachment_xid);
	//�������ļ����û��� _FILE_ATTACHMENT_SHARELIST_DO_
	CC_SYNTHESIZE(string, xshareList, XshareList);
	//�ļ���ʾ˳��
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	file_attachment_sharelistDO() {
		ATTACHMENT_XID = "";
		xshareList = "";
		xorderColumn = 1;
	}
};

#endif // !_FILE_ATTACHMENT_SHARELIST_DO_


