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
#ifndef _FILE_ATTACHMENT_EDITORLIST_DO_
#define _FILE_ATTACHMENT_EDITORLIST_DO_
#include "../../GlobalInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class file_attachment_editorlistDO
{
	// �����ĸ���Ψһ��ʶ��
	CC_SYNTHESIZE(string, ATTACHMENT_XID, attachment_xid);
	// �洢�༭��Ա���б�
	CC_SYNTHESIZE(string, xeditorlist, XeditorList);
	// ���ڶ���༭��Ա����������ȼ�
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);

public:
	file_attachment_editorlistDO() {
		ATTACHMENT_XID = "";
		xeditorlist = "";
		xorderColumn = 1;

	}
};

#endif // !_FILE_ATTACHMENT_EDITORLIST_DO_
