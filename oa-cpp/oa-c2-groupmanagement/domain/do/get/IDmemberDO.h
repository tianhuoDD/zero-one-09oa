#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 23:19:41 CST
*/
//��ͼDO
#ifndef _IDMEMBERDO_DO_
#define _IDMEMBERDO_DO_
#include "../../../Macros.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class IDmemberDO
{

	// ���
	//CC_SYNTHESIZE(uint64_t, id, Id);

	//����
	CC_SYNTHESIZE(string, xname, Xname);
	//�㼶����
	CC_SYNTHESIZE(string, xunitLevelName, Xunit_level_name);
public:
	IDmemberDO() {
		xname = "";
		xunitLevelName = "";
	}
};

#endif // !_IDMEMBERDO_DO_
