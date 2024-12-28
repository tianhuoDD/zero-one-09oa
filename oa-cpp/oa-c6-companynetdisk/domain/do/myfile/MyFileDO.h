#pragma once

#ifndef _MYFILE_DO_
#define _MYFILE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class MyFileDO
{

	//CC_SYNTHESIZE(uint64_t, id, Id);
	//"2023-04-02 15:30:00"
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(string, xextension, Xextension);
	CC_SYNTHESIZE(string, xfolder, Xfolder);
	CC_SYNTHESIZE(string, xdeepPath, XdeepPath);

	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	CC_SYNTHESIZE(uint64_t, xlength, Xlength);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xperson, Xperson);
	CC_SYNTHESIZE(string, xstorage, Xstorage);


	//CC_SYNTHESIZE(int, age, Age);
public:
	MyFileDO() {
		xid = "";
		xcreateTime = "";
		xupdateTime = "";
		xextension = "";
		xfolder = "";
		xdeepPath = "";

		xlastUpdatePerson = "";
		xlastUpdateTime = "";
		xlength = 0;
		xname = "";
		xperson = "";
		xstorage = "";

	}
};

#endif // !_SAMPLE_DO_
