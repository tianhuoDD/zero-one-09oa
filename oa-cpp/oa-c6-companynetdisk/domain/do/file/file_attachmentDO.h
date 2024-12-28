#pragma once
#ifndef _FILE_ATTACHMENTDO_H_
#define _FILE_ATTACHMENTDO_H_
#include "../../GlobalInclude.h"

class file_attachmentDO {
	//	文件id
	CC_SYNTHESIZE(string, xid, Xid);
	//	创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	//	更新时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// 序列号
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	//	扩展名
	CC_SYNTHESIZE(string, xextension, Xextension);

	CC_SYNTHESIZE(string, xfolder, Xfolder);
	//	深度
	CC_SYNTHESIZE(int, xdeepPath, XdeepPath);

	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	//	文件大小
	CC_SYNTHESIZE(uint64_t, xlength, Xlength);
	//	文件名称
	CC_SYNTHESIZE(string, xname, Xname);

	CC_SYNTHESIZE(string, xperson, Xperson);

	CC_SYNTHESIZE(string, xstorage, Xstorage);



public:
	file_attachmentDO() {
		xid = "";
		xcreateTime = "";
		xupdateTime = "";
		xsequence = " ";
		xextension = "";
		xfolder = "";
		xdeepPath = 0;

		xlastUpdatePerson = "";
		xlastUpdateTime = "";
		xlength = 0;
		xname = "";
		xperson = "";
		xstorage = "";
	}
};


#endif // !_FILE_ATTACHMENTDO_H_
