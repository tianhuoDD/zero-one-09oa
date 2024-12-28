#pragma once
#ifndef _FOLDER_FOLDERQUERYDO_H_
#define _FOLDER_FOLDERQUERYDO_H_
#include "../../GlobalInclude.h"
#include "../file/file_attachmentDO.h"
#include "../folder/file_folderDO.h"
class folder_queryDO :public file_attachmentDO {
	// Ŀ¼���
	CC_SYNTHESIZE(string, xid, folder_Xid);
	// Ŀ¼����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, folder_XcreateTime);
	// Ŀ¼���к�
	CC_SYNTHESIZE(string, xsequence, folder_Xsequence);
	// Ŀ¼����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, folder_XupdateTime);
	// Ŀ¼��
	CC_SYNTHESIZE(string, xname, folder_Xname);
	// Ŀ¼ӵ����
	CC_SYNTHESIZE(string, xperson, folder_Xperson);


public:
	folder_queryDO() {
		xid = "123456";
		xcreateTime = "2024-10-23 21:24";
		xsequence = "654321";
		xupdateTime = "2025-10-23 21:24";
		xname = "c6";
	}
};


#endif // !_FOLDER_FOLDERQUERYDO_H_
