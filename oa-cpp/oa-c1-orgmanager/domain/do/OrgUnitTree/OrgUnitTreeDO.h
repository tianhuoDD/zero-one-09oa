#pragma once
#ifndef _ORGUNITTREEDO_H_
#define _ORGUNITTREEDO_H_

#include "../DoInclude.h"

/**
 * ��֯��λ���ݿ�ʵ��
 */
class OrgUnitTreeDO
{
    CC_SYNTHESIZE(string, xid, Xid);               // ΨһID
    CC_SYNTHESIZE(string, xname, Xname);           // ��λ����
    CC_SYNTHESIZE(string, xlevelName, XlevelName); // �㼶����
    CC_SYNTHESIZE(int, xlevel, Xlevel);            // �㼶
    CC_SYNTHESIZE(string, xunique, Xunique);       // Ψһ��ʶ
    CC_SYNTHESIZE(string, xsuperior, Xsuperior);   // �ϼ�ID
};

#endif // !_ORGUNITTREEDO_H_
