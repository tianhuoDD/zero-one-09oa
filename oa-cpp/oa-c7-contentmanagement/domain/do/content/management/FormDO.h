#pragma once
/*
	//���ݿ��ӳ��
	author��Niuniu
*/
#ifndef _FORM_DO_H_
#define _FORM_DO_H_
#include "../../DoInclude.h"

class FormDO {
	// ���
	CC_SYNTHESIZE(string, xid, Id);
	//����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, UpdateTime);
	//����
	CC_SYNTHESIZE(string, xalias, Alias);
	//����
	CC_SYNTHESIZE(string, xdescription, Description);
	//�༭��
	CC_SYNTHESIZE(string, xeditor, Editor);
	//����
	CC_SYNTHESIZE(string, xname, FromName);
	//����
	CC_SYNTHESIZE(string, xproperties, Properties);
public:
	FormDO() {
		xid = "xuehuasuanfa";
		xupdateTime = "";
		xalias = "FormTest";
		xdescription = "Use_Test";
		xeditor = "Niuniu";
		xname = "FormTest";
		xproperties = "i' don't know";
	}
};



#endif // !_FORM_DO_H_
