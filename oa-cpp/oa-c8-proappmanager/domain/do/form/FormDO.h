#pragma once
#ifndef _FORM_DO_
#define _FORM_DO_
#include "../DoInclude.h"

/**
 * ���̱����ݿ�ʵ����
 */
class FormDO {
	// ����ʶ
	CC_SYNTHESIZE(string, xid, Id);
	// ����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, CreateTime);
	// ����
	CC_SYNTHESIZE(string, xsequence, Sequence);
	// ����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, UpdateTime);
	// �ֲ�ʽ���ӣ�distributeFactor����
	CC_SYNTHESIZE(string, xdistributeFactor, DistributeFactor);
	// ����
	CC_SYNTHESIZE(string, xalias, Alias);
	// Ӧ�ñ�ʶ
	CC_SYNTHESIZE(string, xapplication, Application);
	// ���
	CC_SYNTHESIZE(string, xcategory, Category);
	// ����
	CC_SYNTHESIZE(string, xdata, Data);
	// ����
	CC_SYNTHESIZE(string, xdescription, Description);
	// �Ƿ�֧���ƶ��ˣ�1��֧�֣�0֧�֣���
	CC_SYNTHESIZE(bool, xhasMobile, HasMobile);
	// ͼ��
	CC_SYNTHESIZE(string, xicon, Icon);
	// ��һ�θ����û�
	CC_SYNTHESIZE(string, xlastUpdatePerson, LastUpdatePerson);
	// ��һ�θ���ʱ��
	CC_SYNTHESIZE(string, xlastUpdateTime, LastUpdateTime);
	// �ƶ�������
	CC_SYNTHESIZE(string, xmobileData, MobileData);
	// ����
	CC_SYNTHESIZE(string, xname, Name);
	// ����
	CC_SYNTHESIZE(string, xproperties, Properties);
	// �����Ͷ�Ӧ��������ӣ�
	CC_SYNTHESIZE(int, xnum, Num);
	// ������汾�������-��id
	CC_SYNTHESIZE(string, xform, Form);
	// ������汾�������-�޸���
	CC_SYNTHESIZE(string, xperson, Person);
};

#endif // !_FORM_DO_
