#pragma once
#ifndef _FILE_ATTACHMENTDO_H_
#define _FILE_ATTACHMENTDO_H_
#include "../../GlobalInclude.h"

class file_attachmentDO {
	//	�ļ�id
	CC_SYNTHESIZE(string, xid, Xid);
	//	����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	//	����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// ���к�
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	//	��չ��
	CC_SYNTHESIZE(string, xextension, Xextension);

	CC_SYNTHESIZE(string, xfolder, Xfolder);
	//	���
	CC_SYNTHESIZE(int, xdeepPath, XdeepPath);

	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	//	�ļ���С
	CC_SYNTHESIZE(uint64_t, xlength, Xlength);
	//	�ļ�����
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
