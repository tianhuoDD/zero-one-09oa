#pragma once
#ifndef _FILE_OPERATION_LOGDO_H_
#define _FILE_OPERATION_LOGDO_H_

#include "../../GlobalInclude.h"

class FileLogDO {
	//	��־id
	CC_SYNTHESIZE(string, xid, Xid);
	//	��������
	CC_SYNTHESIZE(int, xOperationType, XOperationType);
	//	����������
	CC_SYNTHESIZE(string, xFromPerson, XFromPerson);
	//	����������
	CC_SYNTHESIZE(string, xToPerson, XToPerson);
	//	����ʱ��
	CC_SYNTHESIZE(string, xOperationTime, XOperationTime);
	//	�ļ�id
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
