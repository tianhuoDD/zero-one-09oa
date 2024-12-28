#pragma once
#ifndef _FOLDER_FOLDERQUERYDO_H_
#define _FOLDER_FOLDERQUERYDO_H_
#include "../../GlobalInclude.h"
#include "../file/file_attachmentDO.h"
#include "../folder/file_folderDO.h"
class folder_queryDO :public file_attachmentDO {
	// 目录编号
	CC_SYNTHESIZE(string, xid, folder_Xid);
	// 目录创建时间
	CC_SYNTHESIZE(string, xcreateTime, folder_XcreateTime);
	// 目录序列号
	CC_SYNTHESIZE(string, xsequence, folder_Xsequence);
	// 目录更新时间
	CC_SYNTHESIZE(string, xupdateTime, folder_XupdateTime);
	// 目录名
	CC_SYNTHESIZE(string, xname, folder_Xname);
	// 目录拥有人
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
