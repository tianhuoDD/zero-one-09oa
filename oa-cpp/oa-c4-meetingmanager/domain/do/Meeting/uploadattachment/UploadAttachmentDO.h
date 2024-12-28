#pragma once

#ifndef _UPLOADATTACHMENT_DO_
#define _UPLOADATTACHMENT_DO_
#include "../../DoInclude.h"

/**
 * �����ļ������ݿ�ʵ����
 */
class UploadAttachmentDO
{
	// �ļ����
	CC_SYNTHESIZE(string, xid, Xid);
	// �ļ�����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// ���к�
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// �ļ�����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// �ļ��������
	CC_SYNTHESIZE(int, xdeepPath, XdeepPath);
	// �ļ���չ������pdf
	CC_SYNTHESIZE(string, xextension, Xextension);
	// ���ִ�и����ļ����û�
	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	// �ļ��������ʱ��
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	// �ļ���С
	CC_SYNTHESIZE(long, xlength, Xlength);
	// ����ID
	CC_SYNTHESIZE(string, xmeeting, Xmeeting);
	// �ļ�����
	CC_SYNTHESIZE(string, xname, Xname);
	// �ļ��洢·�� ��FastDFS
	CC_SYNTHESIZE(string, xstorage, Xstorage);
	// ����Ƿ��ǻ���ժҪ
	CC_SYNTHESIZE(bool, xsummary, Xsummary);
public:
	UploadAttachmentDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdeepPath = 0;
		xextension = "";
		xlastUpdatePerson = "";
		xlength = 0;
		xmeeting = "";
		xname = "";
		xstorage = "";
		xsummary = false;	
	}
};

#endif // !_UPLOADATTACHMENT_DO_
