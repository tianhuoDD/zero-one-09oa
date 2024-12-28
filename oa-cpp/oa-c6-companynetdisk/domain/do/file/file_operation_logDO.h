#pragma once
#ifndef _FILE_OPERATION_LOGDO_H_
#define _FILE_OPERATION_LOGDO_H_

#include "../../GlobalInclude.h"

class FileLogDO {
	//	日志id
	CC_SYNTHESIZE(string, xid, Xid);
	//	操作类型
	CC_SYNTHESIZE(int, xOperationType, XOperationType);
	//	发起者名称
	CC_SYNTHESIZE(string, xFromPerson, XFromPerson);
	//	接受者名称
	CC_SYNTHESIZE(string, xToPerson, XToPerson);
	//	操作时间
	CC_SYNTHESIZE(string, xOperationTime, XOperationTime);
	//	文件id
	CC_SYNTHESIZE(string, file_attachment_id, File_attachment_id);
public:
	FileLogDO() {
		xid = "";
		xOperationType = 1;
		xFromPerson = "";
		xToPerson = "";
		xOperationTime = "";
		file_attachment_id = "";
	}
};

#endif // !_FILE_OPERATION_LOGDO_H_
