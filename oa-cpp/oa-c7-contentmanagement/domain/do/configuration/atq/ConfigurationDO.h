#pragma once

#ifndef _CONFIGURATIONDO_
#define _CONFIGURATIONDO_
#include "../../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ConfigurationDO
{
	//ѡ������
	CC_SYNTHESIZE(string, xcreatorUnitName,XcreatorUnitName);
	//�����ʶ
	CC_SYNTHESIZE(string,  xappId, XappId);
	//�������
	CC_SYNTHESIZE(string, xalias, Xalias);
	//�ĵ�����
	CC_SYNTHESIZE(string, xdocumentType, XdocumentType);
	//����ʱ�Ƿ�����Ϣ
	CC_SYNTHESIZE(string, xsendNotify, XsendNotify);
	//ʹ������
	CC_SYNTHESIZE(string, process, Process);
	//�ɼ���Χ
	CC_SYNTHESIZE(string, range, Range);
	//������
	CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
	//������
	CC_SYNTHESIZE(string, xmanagePerson, XmanagePerson);

	// ����
	CC_SYNTHESIZE(string, name, Name);
public:
	ConfigurationDO() {
		xcreatorUnitName = "";
		xappId = "";
		xalias = "";
		xdocumentType = "";
		xsendNotify = "";
		process = "";
		range = "";
		xcreatorPerson = "";
		xmanagePerson = "";
	}
};

#endif // !_SAMPLE_DO_
